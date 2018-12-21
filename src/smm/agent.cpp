#include "smm/agent.hpp"

Agent::Agent(float x, float y, bool (*releaseCondition)(Particle &, float))
	: RetainingAttractor(x, y, AGENT_ATTRACTION_FORCE, AGENT_HOLDING_RADUIS, releaseCondition)
{

}

Agent::~Agent(){}
