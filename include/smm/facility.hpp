#ifndef FACILITY_HPP
#define FACILITY_HPP

#include "agent.hpp"
#include "groundmath.h"


// release particle condition
bool continueToProcess(Particle &p, float dTime);

class Facility : public Agent {
public:
	Facility(float x, float y, size_t capacity,
			 float cultivationTime, DISTRIBUTION_LAW cultivationLaw);
	~Facility();
protected:
	DISTRIBUTION_LAW cultivationLaw;
};

#endif // FACILITY_HPP
