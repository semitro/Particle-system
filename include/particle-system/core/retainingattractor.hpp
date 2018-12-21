#ifndef RETAININGATTRACTOR_HPP
#define RETAININGATTRACTOR_HPP

#include "attractor.hpp"

// hold particle
class RetainingAttractor : public Attractor{

public:
	RetainingAttractor(float x, float y, float m,
					   float retainRaduis,
						bool (*releaseCondition)(Particle &p, float deltaTime));
	virtual ~RetainingAttractor() override;
	// Attractor interface
	virtual void attract(vector<Particle> &particles, float deltaTime) override;
protected:
	float myRadius;
	bool (*releaseCondition)(Particle &p, float deltaTime);
	float m;
private:
	bool here(Particle &p);
};

#endif // RETAININGATTRACTOR_HPP
