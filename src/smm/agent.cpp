#include "smm/agent.hpp"

vector<Transact*> *Agent::allTheTransacts = new vector<Transact*>(INITAL_TRANSACT_VECOTOR_SIZE);

Agent::Agent(float x, float y)
	: RetainingAttractor(x, y, AGENT_ATTRACTION_FORCE, AGENT_HOLDING_RADUIS)
{
}

Agent::~Agent(){}

bool Agent::doINeedAttract(Particle &p, float deltaTime){
	return amIGoingToHandle(getTransact(p.id), deltaTime);
}

void Agent::particleHereHandler(Particle &p, float deltaTime)
{
	transactHereHandler(getTransact(p.id), deltaTime);
}

void Agent::particleReleaseHandler(Particle &p, float deltaTime)
{
	transactReleaseHandler(getTransact(p.id), deltaTime);
}

bool Agent::releaseCondition(Particle &p, float deltaTime)
{
	return isItTimeToReleaseTransact(getTransact(p.id), deltaTime);
}


Transact &Agent::getTransact(unsigned long particle_id)
{
	if(allTheTransacts->size() <= particle_id)
		allTheTransacts->resize(particle_id + 100);

	if((*allTheTransacts)[particle_id] == nullptr){
		(*allTheTransacts)[particle_id] = new Transact(particle_id);
	}

	return *(*allTheTransacts)[particle_id];
}
