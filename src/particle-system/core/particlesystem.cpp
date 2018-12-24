#include "particle-system/core/particlesystem.hpp"
#include <QtDebug>

ParticleSystem::ParticleSystem(Emitter *emitter, ParticleLaw *law)
	:ParticleSystem(emitter, law, new vector<Attractor*>())
{

}

ParticleSystem::ParticleSystem(Emitter *emitter, ParticleLaw *law,
							   vector<Attractor*> *attractors)
	:emitter(emitter), attractors(attractors), law(law)
{
	this->particles = new vector<Particle>();
	doEmission(0);
}
const vector<Particle> *ParticleSystem::getParticles()
{
    return this->particles;
}


void ParticleSystem::doEmission(float time)
{
	vector<Particle> newOnes = this->emitter->emit(time);
	for(auto p : newOnes){
		this->particles->push_back(p);
	}
}

void ParticleSystem::update(float delta_time){
//	qDebug() << "Update PS";
	this->doEmission(delta_time);
//	qDebug() << "attracting..";
	for(size_t i = 0; i < this->attractors->size(); i++)
		this->attractors->at(i)->attract(*this->particles, delta_time);
//	qDebug() << "lawing..";
	this->law->process(*this->particles, delta_time);
//	qDebug() << "lawing ended..";
}


