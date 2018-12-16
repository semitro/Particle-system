#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "particle-system/core/particle.hpp"
#include <vector>

using std::vector;

class Emitter
{
public:
	Emitter(){}
	virtual ~Emitter(){}
	virtual vector<Particle> emit(float currentTime)=0;
};

#endif // EMITTER_HPP
