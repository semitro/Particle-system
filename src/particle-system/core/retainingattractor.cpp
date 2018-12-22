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

//		if(!doINeedAttract(p, dT))
//			continue;


		if(here(p)){
			particleHereHandler(p, dT);
			particlesNumber++;
			p.vx = 0;
			p.vy = 0;
			p.x = 0;
			p.y = 0;
		}
		else{ // attract only if it's not in the circle
			float dx = this->x - p.x;
			float dy = this->y - p.y;
			p.vx += m*dT * (dx > 0 ? 1 : -1);
			p.vy += m*dT * (dy > 0 ? 1 : -1);
		}

		if(here(p) && releaseCondition(p, dT)){
			particlesNumber--;
			particleReleaseHandler(p, dT);
//			p.vx = 15.f;
//			p.vy = -10.f;
		}
	}
}
