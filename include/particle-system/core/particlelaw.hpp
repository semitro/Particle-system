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
	ParticleLaw(void (*law)(vector<Particle> &));
	void process(vector<Particle> &p);
private:
	void (*law)(vector<Particle> &);
};

#endif // PARTICLELAW_H
