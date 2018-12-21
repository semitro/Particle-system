#include "smm/facility.hpp"


bool continueToProcess(Particle &p, float dTime){
	return rand()% 2 == 0;
}

Facility::Facility(float x, float y, size_t capacity,
		 float cultivationTime, DISTRIBUTION_LAW cultivationLaw)
	: Agent(x, y, &continueToProcess)
{

}

Facility::~Facility(){}
