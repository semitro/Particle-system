#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <vector>

#include "particle-system/core/particle.hpp"
#include "particle-system/core/emitter.hpp"
#include "particle-system/core/attractor.hpp"
#include "particle-system/core/particlelaw.hpp"

using namespace sf;
using std::vector;

class ParticleSystem
{
public:
	ParticleSystem(Emitter *emitter, ParticleLaw *law, vector<Attractor*> *attractors);
	ParticleSystem(Emitter *emitter, ParticleLaw *law);
    const VertexArray *getParticles();
	void update(float delta_time);
private:
	VertexArray *vertexes;
	vector<Particle> *particles;
	Emitter *emitter;
	vector<Attractor*> *attractors;
	ParticleLaw *law;
	void doEmission(float time);
    void particlesToVertexes();
};

#endif // PARTICLESYSTEM_HPP
