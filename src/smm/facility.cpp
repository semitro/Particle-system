#include "smm/facility.hpp"

Facility::Facility(float x, float y, size_t capacity,
		 float cultivationTime, DISTRIBUTION_LAW cultivationLaw)
	: Agent(x, y)
{

}

Facility::~Facility(){}

bool Facility::releaseCondition(Particle &p, float deltaTime)
{
	return false;
}
