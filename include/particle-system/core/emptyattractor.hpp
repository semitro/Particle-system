#ifndef EMTPY_ATTRACTOR_HPP
#define EMPTY_ATTRACTOR_HPP

#include "particle-system/core/particle.hpp"
#include "particle-system/core/attractor.hpp"
#include <vector>
#include <cstdlib>

using std::vector;

class EmptyAttractor : public Attractor
{
public:
	EmptyAttractor():Attractor(0, 0){}
	virtual ~EmptyAttractor(){}
	virtual void attract(vector<Particle> &particles,
						 float deltaTime){}
};

#endif // EMRPTY_ATTRACTOR_HPP
