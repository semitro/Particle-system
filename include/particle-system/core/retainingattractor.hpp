#ifndef RETAININGATTRACTOR_HPP
#define RETAININGATTRACTOR_HPP

#include "attractor.hpp"


// hold particle
class RetainingAttractor : public Attractor{

public:
	RetainingAttractor(float x, float y, float m,
					   float retainRaduis);
	virtual ~RetainingAttractor() override;
	// Attractor interface
	virtual void attract(vector<Particle> &particles, float deltaTime) override;
protected:
	float myRadius;
	virtual bool releaseCondition      (Particle &p, float deltaTime)=0;
	virtual bool doINeedAttract        (Particle &p, float deltaTime)=0;
	virtual void particleHereHandler   (Particle &p, float deltaTime)=0;
	virtual void particleReleaseHandler(Particle &p, float deltaTime)=0;

	float m;
	size_t particlesNumber; // what are in the zone of retaining
private:
	bool here(Particle &p);
};

#endif // RETAININGATTRACTOR_HPP
