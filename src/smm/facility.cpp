#include "smm/facility.hpp"

Facility::Facility(float x, float y, size_t capacity,
		 float cultivationTime, DISTRIBUTION_LAW cultivationLaw)
	: Agent(x, y), b(cultivationTime), distributionLaw(cultivationLaw)
{

}

Facility::~Facility(){}

bool Facility::canAccept()
{
	return particlesNumber < capacity;
}

bool Facility::isItTimeToReleaseTransact(Transact &p, float deltaTime)
{
	p.facilityData[0].timeOfBeing += deltaTime;
	return p.facilityData[0].timeOfBeing >= b;
}

bool Facility::amIGoingToHandle(Transact &t, float dT)
{
	return false;
}

void Facility::transactHereHandler(Transact &t, float deltaTime)
{

}

void Facility::transactReleaseHandler(Transact &p, float deltaTime)
{

}
