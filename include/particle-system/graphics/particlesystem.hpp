#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <vector>

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"
#include "particle-system/core/particlelaw.hpp"

using namespace sf;
using std::vector;

class ParticleSystem
{
public:
	ParticleSystem(Emitter *emitter, ParticleLaw *law);
	const VertexArray* getVertexes();
	void update(float delta_time);
private:
	VertexArray *vertexes;
	vector<Particle> *particles;
	Emitter *emitter;
	ParticleLaw *law;
	void particleToVertexes();
	void doEmission(float time);
};

#endif // PARTICLESYSTEM_HPP
