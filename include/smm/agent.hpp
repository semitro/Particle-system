#ifndef AGENT_HPP
#define AGENT_HPP

#include "particle-system/core/retainingattractor.hpp"
#include "transact.hpp"
#include "groundmath.h"

#define AGENT_ATTRACTION_FORCE 25.0f
#define AGENT_HOLDING_RADUIS   10.5f
#define INITAL_TRANSACT_VECOTOR_SIZE 1000000

class Agent : public RetainingAttractor{
public:
	Agent(float x, float y);
	~Agent();

	static vector<Transact*> *allTheTransacts;
	// RetainingAttractor interface
protected:
	virtual bool doINeedAttract(Particle &p, float deltaTime) final;
	virtual bool amIGoingToHandle(Transact &t, float dT)=0;

	virtual void particleHereHandler(Particle &p, float deltaTime) final;
	virtual void transactHereHandler(Transact &t, float deltaTime)=0;

	virtual void particleReleaseHandler(Particle &p, float deltaTime) final;
	virtual void transactReleaseHandler(Transact &p, float deltaTime)=0;

	virtual bool releaseCondition(Particle &p, float deltaTime) final;
	virtual bool isItTimeToReleaseTransact(Transact &t, float deltaTime)=0;

	virtual void newUpdateHanlder()=0;
private:
	Transact &getTransact(unsigned long particle_id);
};

#endif // FACILITY_HPP
