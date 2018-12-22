#include "smm/smmqueue.hpp"

SmmQueue::SmmQueue(float x, float y, size_t capacity, Facility *master)
	:Agent(x, y), capacity(capacity), master(master)
{

}

SmmQueue::~SmmQueue(){}

bool SmmQueue::amIGoingToHandle(Transact &t, float dT)
{

}

void SmmQueue::transactHereHandler(Transact &t, float deltaTime)
{

}

void SmmQueue::transactReleaseHandler(Transact &p, float deltaTime)
{

}

bool SmmQueue::isItTimeToReleaseTransact(Transact &t, float deltaTime)
{
	return master->canAccept();
}
