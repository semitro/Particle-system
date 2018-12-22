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
protected:
	bool continueToProcess(Particle &p, float dTime);
	DISTRIBUTION_LAW cultivationLaw;

	// RetainingAttractor interface
protected:
	virtual bool releaseCondition(Particle &p, float deltaTime) override;
};

#endif // FACILITY_HPP
