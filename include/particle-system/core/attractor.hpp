#ifndef ATTRACTOR_HPP
#define ATTRACTOR_HPP

#include "particle-system/core/particle.hpp"
#include <vector>
#include <cstdlib>

using std::vector;

class Attractor
{
public:
	Attractor(float posX, float posY):x(posX),y(posY){}
	virtual ~Attractor(){}
	virtual void attract(vector<Particle> &particles,
						 float deltaTime)=0;
protected:
	float x, y;
};

#endif // ATTRATOR_HPP
