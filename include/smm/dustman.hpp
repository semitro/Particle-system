#ifndef DUSTMAN_HPP
#define DUSTMAN_HPP

#include "agent.hpp"

// attract killed particles
class DustMan : public Agent {
public:
	DustMan(float x, float y);
protected:
	virtual bool amIGoingToHandle(Transact &t, float dT) override;
	virtual void transactHereHandler(Transact &t, float deltaTime) override;
	virtual void transactReleaseHandler(Transact &p, float deltaTime) override;
	virtual bool isItTimeToReleaseTransact(Transact &t, float deltaTime) override;

	virtual void newUpdateHanlder() override;
};

#endif // DUSTMAN_HPP
