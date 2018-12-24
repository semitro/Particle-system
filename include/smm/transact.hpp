#ifndef TRANSACT_H
#define TRANSACT_H

#include "particle-system/core/particle.hpp"

// state of transact in facility
enum StateInFacility{
	READY,
	CULTIVATING,
	PROCESSED
};

enum StateInQueue{
	HAVE_NEVER_BEEN,
	QUEUEING,
	LEAVED
};

struct FacilityData{
	float timeOfBeing;
	float currentTime;
	StateInFacility state;
};

struct QueueData{
	float timeOfBeing;
	float currentTime;
	StateInQueue state;
};

struct Transact{

	Transact(unsigned long particleId)
		: id(counter++), particleId(particleId)
	{
		facilityData[0].state = StateInFacility::READY;
		queueData[0].state = StateInQueue::HAVE_NEVER_BEEN; // HAVE NEVER BEEN!!
		queueData[0].timeOfBeing = 0.f;
		queueData[0].currentTime = 0.f;
		facilityData[0].currentTime = 0.f;
		facilityData[0].timeOfBeing = 0.f;
	}

	unsigned long  id, particleId;
	static unsigned long counter;
	FacilityData facilityData[4];
	QueueData       queueData[4];
};
#endif // TRANSACT_H
