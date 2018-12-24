#include "smm/facility.hpp"
#include <QtDebug>

Facility::Facility(float x, float y, size_t capacity,
		 float cultivationTime, DISTRIBUTION_LAW cultivationLaw)
	: Agent(x, y), b(cultivationTime),
	  cultivationLaw(cultivationLaw),
	  capacity(capacity),
	  transactsNumber(0), attracting(0)
{
	if(this->cultivationLaw == DISTRIBUTION_LAW::DET)
			this->nextCultTime = b;
		else
			this->nextCultTime = nextExpRand(b);
}

Facility::~Facility(){}

bool Facility::canAccept()
{
	return transactsNumber < capacity;
}
size_t Facility::howManyCanAccept(){
	return capacity - transactsNumber;
}
size_t Facility::getTransactsNumber()
{
	return this->transactsNumber;
}

bool Facility::isItTimeToReleaseTransact(Transact &t, float deltaTime)
{
	if(t.facilityData[0].timeOfBeing >= this->nextCultTime){

		if(this->cultivationLaw == DISTRIBUTION_LAW::DET)
			this->nextCultTime = b;
		else{
			qDebug() << "exp" << nextCultTime;
			this->nextCultTime = nextExpRand(b);
		}

		return  true;
	}
		else

	return false;
}

bool Facility::amIGoingToHandle(Transact &t, float dT)
{
//	qDebug() << "accept: " << howManyCanAccept();
	if(t.queueData[0].state == StateInQueue::LEAVED
			&& t.facilityData[0].state == StateInFacility::READY
			&& canAccept()
			&& attracting < howManyCanAccept()// between
			){
		this->attracting++;
		return true;
	}
	else
		return false;
}

void Facility::transactHereHandler(Transact &t, float deltaTime)
{
	if(t.facilityData[0].state == StateInFacility::READY
			&& canAccept()){
		t.facilityData[0].state = StateInFacility::CULTIVATING;
		this->transactsNumber++;
		qDebug() << "TRANSACT ENTER FACILITY " << transactsNumber;
	}

	if(t.facilityData[0].state == StateInFacility::CULTIVATING){
		t.facilityData[0].timeOfBeing += deltaTime;
		qDebug() << "cultivating " << t.facilityData[0].timeOfBeing;
	}
}
void Facility::transactReleaseHandler(Transact &p, float deltaTime)
{
	if(p.facilityData[0].state == StateInFacility::CULTIVATING){
		this->transactsNumber--;
		this->attracting--;
		qDebug() << "TRANSACT LEAVED FACILITY " << transactsNumber;
		p.facilityData[0].state = StateInFacility::PROCESSED;
	}
}

void Facility::newUpdateHanlder()
{

}
