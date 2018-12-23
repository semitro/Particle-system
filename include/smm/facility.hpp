#ifndef FACILITY_HPP
#define FACILITY_HPP

#include "agent.hpp"
#include "groundmath.h"


// release particle condition

class Facility : public Agent {
public:
	Facility(float x, float y, size_t capacity,
			 float cultivationTime, DISTRIBUTION_LAW cultivationLaw);
	~Facility() override;
	bool canAccept();
	size_t howManyCanAccept();
	size_t getTransactsNumber();
protected:
	bool continueToProcess(Particle &p, float dTime);
	DISTRIBUTION_LAW cultivationLaw;
	size_t capacity;
	size_t transactsNumber;
	size_t attracting; // between queue and facility
	float b; // cultivation time
	DISTRIBUTION_LAW distributionLaw;

	// Agent interface
protected:
	virtual bool isItTimeToReleaseTransact(Transact &t, float deltaTime) override;
	virtual bool amIGoingToHandle(Transact &t, float dT) override;
	virtual void transactHereHandler(Transact &t, float deltaTime) override;
	virtual void transactReleaseHandler(Transact &p, float deltaTime) override;
};

#endif // FACILITY_HPP
