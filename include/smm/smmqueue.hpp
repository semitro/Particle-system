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


class SmmQueue : public Agent{
public:
	SmmQueue(float x, float y, size_t capacity, Facility *master);
	~SmmQueue();
private:
	Facility* master;
	size_t 	  capacity;

	// Agent interface
protected:
	virtual bool amIGoingToHandle(Transact &t, float dT) override;
	virtual void transactHereHandler(Transact &t, float deltaTime) override;
	virtual void transactReleaseHandler(Transact &p, float deltaTime) override;
	virtual bool isItTimeToReleaseTransact(Transact &t, float deltaTime) override;
};

#endif // SMMQUEUE_HPP
