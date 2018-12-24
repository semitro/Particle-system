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
	for(size_t i = 0; i < particles.size(); i++){
		Particle &p = particles[i];

		if(doINeedAttract(p, dT)){
			float dx = this->x - p.x;
			float dy = this->y - p.y;
			float dyCoef = std::abs(dy/dx);
			p.vx  = m * (dx > 0 ? 1.f : -1.f);
			p.vy  = m * (dy > 0 ? dyCoef : -dyCoef);
//			continue; // if just attract
		}
		// particle here or already there
		if(here(p)){
			particleHereHandler(p, dT);
			particlesNumber++;
			if(releaseCondition(p, dT)){
				particlesNumber--;
				particleReleaseHandler(p, dT);
				qDebug() << "release\n";
			}
			else{
				p.vx = 0;
				p.vy = 0;
			}
		}
	}
}
