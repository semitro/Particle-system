#include "particle-system/graphics/particlesystem.hpp"

ParticleSystem::ParticleSystem(Emitter *emitter, ParticleLaw *law)
	:ParticleSystem(emitter, law, new vector<Attractor*>())
{

}

ParticleSystem::ParticleSystem(Emitter *emitter, ParticleLaw *law,
							   vector<Attractor*> *attractors)
	:emitter(emitter), attractors(attractors), law(law)
{
	this->particles = new vector<Particle>();
	this->vertexes  = new VertexArray(PrimitiveType::Points);

	doEmission(0);
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
}

void ParticleSystem::doEmission(float time)
{
	vector<Particle> newOnes = this->emitter->emit(time);
	for(auto p : newOnes){
		this->particles->push_back(p);
		this->vertexes->append(Vertex());
	}
}

void ParticleSystem::update(float delta_time){
	this->doEmission(delta_time);
	this->law->process(*this->particles);
	for(size_t i = 0; i < this->attractors->size(); i++)
		this->attractors->at(i)->attract(*this->particles, delta_time);

	this->particleToVertexes();
}

