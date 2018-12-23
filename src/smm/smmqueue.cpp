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

bool SmmQueue::amIGoingToHandle(Transact &t, float dT)
{
	return t.queueData[0].state == StateInQueue::HAVE_NEVER_BEEN;
}
void SmmQueue::transactHereHandler(Transact &t, float deltaTime)
{
	if(t.queueData->state == StateInQueue::HAVE_NEVER_BEEN){
//			&& this->trasactsHere < capacity){
		trasactsHere++;
		t.queueData[0].state = StateInQueue::QUEUEING;
	}

//	if(t.queueData[0].state != StateInQueue::LEAVED)
//		t.queueData[0].state = t.q
}

// what does it mean to release transact?
void SmmQueue::transactReleaseHandler(Transact &p, float deltaTime)
{
	if(p.queueData[0].state == StateInQueue::QUEUEING){
		trasactsHere--;
		p.queueData[0].state = LEAVED;
	}
}

bool SmmQueue::isItTimeToReleaseTransact(Transact &t, float deltaTime)
{
	t.queueData[0].timeOfBeing += deltaTime;
	return t.queueData[0].timeOfBeing > 50.f;
	// master->canAccept();
}
