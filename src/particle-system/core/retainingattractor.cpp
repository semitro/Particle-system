#include "particle-system/core/retainingattractor.hpp"

RetainingAttractor::RetainingAttractor(float x, float y, float m,
									   float retainRaduis,
									   bool (*releaseCondition)(Particle &, float))
	: Attractor(x, y),
	  m(m),
	  myRadius(retainRaduis),
	  releaseCondition(releaseCondition)
{

}

RetainingAttractor::~RetainingAttractor(){}

bool RetainingAttractor::here(Particle &p){
	// check if the particle is in the circle
	return (p.x - this->x)*(p.x - this->x) +
			(p.y - this->y)*(p.y - this->y) <= myRadius * myRadius;
}
void RetainingAttractor::attract(vector<Particle> &particles, float dT){
	for(size_t i = 0; i < particles.size(); i++){
		Particle &p = (particles[i]);
		float dx = this->x - p.x;
		float dy = this->y - p.y;

		p.vx += m*dx*dT;
		p.vy += m*dy*dT;

		if(here(p) && !releaseCondition(p, dT)){
			p.vx = 0;
			p.vy = 0;
		}
	}
}
