#ifndef SMMQUEUE_HPP
#define SMMQUEUE_HPP

#include "agent.hpp"
#include "facility.hpp"

#define PARTICLE_PURE         0
#define PARTICLE_PURE         0
#define PARTICLE_QUEUING 	  1

#define PARTICLE_LEAVED_QUEUE 3
#define PARTICLE_QUEUING 	  1
#define PARTICLE_LEAVED_QUEUE 3


class SmmQueue : public Agent
{
public:
	SmmQueue(float x, float y, size_t capacity, Facility *master);
	virtual ~SmmQueue() override;

	size_t getTransactsNumber();
private:
	Facility* master;
	size_t 	  capacity;
	size_t    trasactsHere;
	size_t    sendedToMaster; // ready to use in F.
	// Agent interface
protected:
	virtual bool amIGoingToHandle(Transact &t, float dT) override;
	virtual void transactHereHandler(Transact &t, float deltaTime) override;
	virtual void transactReleaseHandler(Transact &p, float deltaTime) override;
	virtual bool isItTimeToReleaseTransact(Transact &t, float deltaTime) override;
	virtual void newUpdateHanlder() override;
};

#endif // SMMQUEUE_HPP
