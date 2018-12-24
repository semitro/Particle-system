#ifndef DOTEMITTER_HPP
#define DOTEMITTER_HPP

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"

#include <vector>
#include "smm/groundmath.h"

using std::vector;
using std::size_t;

class DotEmitter : public Emitter
{
public:
	DotEmitter(float posX, float posY, float mTime, size_t maxEmissions, DISTRIBUTION_LAW distribution);
	virtual ~DotEmitter();
	virtual vector<Particle> emit(float deltaTime) override;

private:
	float mTime; //
	float nextEmissionTime;
	size_t maxEmissions;
	size_t emitted;
	DISTRIBUTION_LAW distribution;
	float calcNextEmission();
};


#endif // DOTEMITTER_HPP
