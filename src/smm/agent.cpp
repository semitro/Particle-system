#include "smm/agent.hpp"

Agent::Agent(float x, float y)
	: RetainingAttractor(x, y, AGENT_ATTRACTION_FORCE, AGENT_HOLDING_RADUIS)
{

}

Agent::~Agent(){}
