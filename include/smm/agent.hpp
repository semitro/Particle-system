#ifndef AGENT_HPP
#define AGENT_HPP

#include "particle-system/core/retainingattractor.hpp"

#define AGENT_ATTRACTION_FORCE 2.f
#define AGENT_HOLDING_RADUIS   49.f
class Agent : public RetainingAttractor{
public:
	Agent(float x, float y);
	~Agent();

	// RetainingAttractor interface
protected:
	virtual bool releaseCondition(Particle &p, float deltaTime)=0;
};

#endif // FACILITY_HPP
