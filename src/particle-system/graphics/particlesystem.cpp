#include "particle-system/graphics/particlesystem.hpp"
#include <iostream>

using std::cerr;
ParticleSystem::ParticleSystem()
{
	this->particles = new vector<Particle>();
	this->vertexes = new VertexArray(PrimitiveType::Points, 150);
	for(int i =0; i < 150; i++)
		this->particles->push_back(Particle(i*7, i*7));
	this->particleToVertexes();
}

const VertexArray* ParticleSystem::getVertexes()
{
	return this->vertexes;
}

void ParticleSystem::particleToVertexes()
{
	for(size_t i = 0; i < this->particles->size(); i++){
		(*vertexes)[i].position.x = (*particles)[i].x;
		(*vertexes)[i].position.y = (*particles)[i].y;
	}
	cerr << "hello";
}


