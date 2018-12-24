#include "smm/dustman.hpp"

DustMan::DustMan(float x, float y)
	:Agent (x, y)
{

}

bool DustMan::amIGoingToHandle(Transact &t, float dT)
{
	return t.facilityData[0].state == StateInFacility::PROCESSED;
}

void DustMan::transactHereHandler(Transact &t, float deltaTime)
{

}

void DustMan::transactReleaseHandler(Transact &p, float deltaTime)
{

}

bool DustMan::isItTimeToReleaseTransact(Transact &t, float deltaTime)
{

}

void DustMan::newUpdateHanlder()
{

}
