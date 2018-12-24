#ifndef GROUNDMATH_H
#define GROUNDMATH_H

#include <stdlib.h>
#include "math.h"

enum DISTRIBUTION_LAW{
	DET,
	EXP
};

float nextExpRand(float expect);

struct SmmParametrs{
	size_t queueSize, facilitySize, maxParticles;
	float b, avgCreationTime;
	DISTRIBUTION_LAW creationLaw, facilityLaw;
};

#endif // GROUNDMATH_H
