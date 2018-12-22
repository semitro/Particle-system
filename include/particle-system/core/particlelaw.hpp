#ifndef PARTICLELAW_H
#define PARTICLELAW_H

#include <Graphics/VertexArray.hpp>
#include "particle-system/core/particle.hpp"
#include <vector>

#define MIN_DISTANCE 0.0005f

using namespace sf;
using std::vector;

class ParticleLaw
{
public:
	ParticleLaw(void (*law)(vector<Particle> &, float deltaTime));
	void process(vector<Particle> &p, float dT);
private:
	void (*law)(vector<Particle> &, float dT);
};

#endif // PARTICLELAW_H
