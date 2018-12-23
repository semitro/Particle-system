#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "particle-system/core/particle.hpp"
#include <vector>
#include <cstdlib>
#include <qobjectdefs.h>

#undef emit

using std::vector;
//std::exponential_distribution<double> distribution(3.5);

class Emitter
{
#define QT_NO_EMIT

public:
	Emitter(float posX, float posY):x(posX),y(posY){}
	virtual ~Emitter();
	virtual vector<Particle> emit(float currentTime)=0;
protected:
	float x, y;
};

#endif // EMITTER_HPP
