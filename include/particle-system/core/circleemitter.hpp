#ifndef CIRCLE_EMMITER_H
#define CIRCLE_EMITTER_H

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"

#include <vector>

using std::vector;
using std::size_t;

class CircleEmitter : public Emitter
{
public:
	CircleEmitter(float posX, float posY, float emissionsPerSecond);
	virtual ~CircleEmitter();
	virtual vector<Particle> emit(float deltaTime);

private:
	float emissionSize;
};


#endif // CIRCLE_EMITTER
