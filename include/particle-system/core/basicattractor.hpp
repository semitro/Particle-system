#ifndef BASIC_ATTRACTOR_HPP
#define BASIC_ATTRACTOR_HPP

#include "particle-system/core/particle.hpp"
#include "particle-system/core/attractor.hpp"
#include <vector>
#include <cstdlib>

#define MIN_DISTANCE 0.000000001f

using std::vector;


class BasicAttractor : public Attractor
{
public:
	BasicAttractor(float posX, float posY, float m);
	virtual ~BasicAttractor(){}
	virtual void attract(vector<Particle> &particles,
									 float deltaTime);
protected:
	float m;
};

#endif // ATTRATOR_HPP
