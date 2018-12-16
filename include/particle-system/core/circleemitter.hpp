#ifndef ONEOFFEMITTER_H
#define ONEOFFEMITTER_H

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"

#include <vector>

using std::vector;
using std::size_t;

class CircleEmitter : public Emitter
{
public:
	CircleEmitter(float posX, float posY, size_t emissionsPerSecond);
	virtual ~CircleEmitter();
	virtual vector<Particle> emit(float deltaTime);

private:
	size_t emissionSize;
};


#endif // ONEOFFEMITTER_H
