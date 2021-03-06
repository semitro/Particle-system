#ifndef ONEOFFEMITTER_H
#define ONEOFFEMITTER_H

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"

#include <vector>
#include <cstdlib>

using std::vector;
using std::size_t;

class OneOffEmitter : public Emitter
{
public:
	OneOffEmitter(float x, float y, float emissionSize);
	virtual ~OneOffEmitter();
	virtual vector<Particle> emit(float currentTime);

private:
	bool emitted;
	size_t emissionSize;
};


#endif // ONEOFFEMITTER_H
