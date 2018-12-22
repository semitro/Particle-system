#ifndef RETAININGATTRACTOR_HPP
#define RETAININGATTRACTOR_HPP

#include "attractor.hpp"

#define PARTICLE_HAS_NOT_BEEN_IN_ATTRACTOR 0
#define PARTICLE_IS_IN_ATTRACTOR 1
#define PARTICLE_HAS_BEEN_IN_ATTRACTOR 2

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
	virtual bool releaseCondition(Particle &p, float deltaTime)=0;
	float m;
private:
	bool here(Particle &p);
};

#endif // RETAININGATTRACTOR_HPP
