#include "smm/facility.hpp"

Facility::Facility(float x, float y, size_t capacity,
		 float cultivationTime, DISTRIBUTION_LAW cultivationLaw)
	: Agent(x, y), b(cultivationTime), distributionLaw(cultivationLaw)
{

}

Facility::~Facility(){}

bool Facility::releaseCondition(Particle &p, float deltaTime)
{
	p.f1 += deltaTime;
	return p.f1 >= b;
}
