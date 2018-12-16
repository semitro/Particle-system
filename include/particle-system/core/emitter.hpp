#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "particle-system/core/particle.hpp"
#include <vector>
#include <cstdlib>

using std::vector;

class Emitter
{
public:
	Emitter(float posX, float posY):x(posX),y(posY){}
	virtual ~Emitter(){}
	virtual vector<Particle> emit(float currentTime)=0;
protected:
	float x, y;
};

#endif // EMITTER_HPP
