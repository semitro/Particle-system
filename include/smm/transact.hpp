#ifndef TRANSACT_H
#define TRANSACT_H

#include "particle-system/core/particle.hpp"

// state of transact in facility
enum StateInFacility{
	READY,
	CULTIVATING,
	PROCESSED
};

struct FacilityData{
	float timeOfBeing;
	float currentTime;
	StateInFacility state;
};


struct Transact{

	Transact(unsigned long particleId)
		: particleId(particleId), id(counter++)
	{}

	unsigned long  id, particleId;
	static unsigned long counter;
	FacilityData facilityData[4];
};
#endif // TRANSACT_H
