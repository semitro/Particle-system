#ifndef DOTEMITTER_HPP
#define DOTEMITTER_HPP

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"

#include <vector>

using std::vector;
using std::size_t;

class DotEmitter : public Emitter
{
public:
	DotEmitter(float posX, float posY, float emissionsPerSecond);
	virtual ~DotEmitter();
	virtual vector<Particle> emit(float deltaTime) override;

private:
	float emissionSize;
};


#endif // DOTEMITTER_HPP
