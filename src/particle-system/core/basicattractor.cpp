#include "particle-system/core/basicattractor.hpp"

BasicAttractor::BasicAttractor(float x, float y, float m)
	:Attractor(x,y), m(m)
{

}


void BasicAttractor::attract(vector<Particle> &particles, float deltaTime)
{

	for(size_t i = 0; i < particles.size(); i++){
		float dx = this->x - particles[i].x;
		float dy = this->y - particles[i].y;
		if(dx < MIN_DISTANCE || dy < MIN_DISTANCE)
			;

		particles[i].vx += this->m*dx*deltaTime;
		particles[i].vy += this->m*dy*deltaTime;
	}
}
