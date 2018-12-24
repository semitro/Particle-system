#include "particle-system/core/retainingattractor.hpp"
#include <QtDebug>

RetainingAttractor::RetainingAttractor(float x, float y, float m,
									   float retainRaduis)
	: Attractor(x, y),
	  myRadius(retainRaduis),
	  m(m)
{

}

RetainingAttractor::~RetainingAttractor(){}

bool RetainingAttractor::here(Particle &p){
	// check if the particle is in the circle
	return 	(p.x - this->x)*(p.x - this->x) +
			(p.y - this->y)*(p.y - this->y) <= myRadius * myRadius;
}
#include <QtDebug>
void RetainingAttractor::attract(vector<Particle> &particles, float dT){
	this->particlesNumber = 0;
	this->newUpdateHanlder();
	for(size_t i = 0; i < particles.size(); i++){
		Particle &p = particles[i];

		if(doINeedAttract(p, dT)){
			float dx = this->x - p.x;
			float dy = this->y - p.y;
			float dyCoef = std::abs(dy/dx);
			p.x   = this->x;
			p.y   = this->y;
//			p.vx  = m * (dx > 0 ? 1.f : -1.f);
//			p.vy  = m * (dy > 0 ? dyCoef : -dyCoef);
		}
		// particle is `here or already there
		if(here(p)){
			particleHereHandler(p, dT);
			particlesNumber++;
			if(releaseCondition(p, dT)){
				particlesNumber--;
				particleReleaseHandler(p, dT);
			}
			else{
				p.vx = 0;
				p.vy = 0;
			}
		}
	}
}
