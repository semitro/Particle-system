#include "smm/smmqueue.hpp"

#include <QtDebug>

SmmQueue::SmmQueue(float x, float y, size_t capacity, Facility *master)
	:Agent(x, y), capacity(capacity), trasactsHere(0), master(master)
{

}

SmmQueue::~SmmQueue(){}

size_t SmmQueue::getTransactsNumber()
{
	return this->trasactsHere;
}
// am I going to attract!!!
bool SmmQueue::amIGoingToHandle(Transact &t, float dT)
{
//	qDebug() << "there " << t.queueData[0].timeOfBeing;
	return t.queueData[0].state == StateInQueue::HAVE_NEVER_BEEN;
//			this->trasactsHere < capacity;
}
void SmmQueue::transactHereHandler(Transact &t, float deltaTime)
{
	if(t.queueData[0].state == StateInQueue::HAVE_NEVER_BEEN)
//			&& this->trasactsHere < capacity){
	{
		trasactsHere++;
		qDebug() << "TRANSACT ENTER QUEUE. num = " << trasactsHere;
		t.queueData[0].state = StateInQueue::QUEUEING;
	}
	if(t.queueData[0].state == StateInQueue::QUEUEING){
		t.queueData[0].timeOfBeing += deltaTime;
		qDebug() << "Queuing:" << t.queueData[0].timeOfBeing;
	}
}

// what does it mean to release transact?
void SmmQueue::transactReleaseHandler(Transact &t, float deltaTime)
{
	if(t.queueData[0].state == StateInQueue::QUEUEING){
		trasactsHere--;
		qDebug() << "TRANSACT LEAVED QUEUE. num = " << trasactsHere;
		t.queueData[0].state = LEAVED;
	}
}

bool SmmQueue::isItTimeToReleaseTransact(Transact &t, float deltaTime)
{
	if(sendedToMaster < master->howManyCanAccept()){
		sendedToMaster++;
		return true;
	}
	return false;
}

void SmmQueue::newUpdateHanlder()
{
	this->sendedToMaster = 0;
}
