#include "particle-system/core/retainingattractor.hpp"
#include <QtDebug>

RetainingAttractor::RetainingAttractor(float x, float y, float m,
									   float retainRaduis)
	: Attractor(x, y),
	  m(m),
	  myRadius(retainRaduis)
{

}

RetainingAttractor::~RetainingAttractor(){}

bool RetainingAttractor::here(Particle &p){
	// check if the particle is in the circle
	return (p.x - this->x)*(p.x - this->x) +
			(p.y - this->y)*(p.y - this->y) <= myRadius * myRadius;
}
void RetainingAttractor::attract(vector<Particle> &particles, float dT){
	this->particlesNumber = 0;
	for(size_t i = 0; i < particles.size(); i++){
		Particle &p = (particles[i]);

		if(!doINeedAttract(p, dT))
			continue;

//		if(p.p1 == PARTICLE_HAS_BEEN_IN_ATTRACTOR)
//			continue;

		float dx = this->x - p.x;
		float dy = this->y - p.y;

		p.vx += m*dx*dT;
		p.vy += m*dy*dT;

		if(here(p)){
			particleHereHandler(p, dT);
			particlesNumber++;
//			p.p1 = PARTICLE_IS_IN_ATTRACTOR;
			p.vx = 0;
			p.vy = 0;
		}

		if(here(p) && releaseCondition(p, dT)){
			particlesNumber--;
			particleReleaseHandler(p, dT);
//			p.p1 = PARTICLE_HAS_BEEN_IN_ATTRACTOR;
			p.vx = 15.f;
			p.vy = -10.f;
		}
//		if(p.p1 == PARTICLE_IS_IN_ATTRACTOR)
	}
}
