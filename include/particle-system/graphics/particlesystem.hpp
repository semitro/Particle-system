#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include <vector>

#include "particle-system/core/particle.hpp"

using namespace sf;
using std::vector;

class ParticleSystem
{
public:
	ParticleSystem();
	const VertexArray* getVertexes();
private:
	VertexArray *vertexes;
	vector<Particle> *particles;
	void (law)(VertexArray &v, vector<Particle> &p);
	void particleToVertexes();
};

#endif // PARTICLESYSTEM_HPP
