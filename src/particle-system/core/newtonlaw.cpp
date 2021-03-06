#include "particle-system/core/newtonlaw.hpp"

void newtonLaw(vector<Particle> &particles, float dT)
{
	for(size_t i = 0; i < particles.size(); i++)
//		for(size_t j = 0; i < particles.size(); i++){

//			float dx = particles[j].x - particles[i].x;
//			float dy = particles[j].y - particles[i].y;
//			float distance = sqrtf(dx*dx + dy*dy);
//			if(distance < 0.00000000001f)
//				continue;
//			float force = G/(distance*distance);
//			particles[i].vx += force*dx;
//			particles[i].vy += force*dy;
//			particles[j].vx -= force*dx;
//			particles[j].vy -= force*dy;

//		}

	for(size_t i = 0; i < particles.size(); i++){
		particles[i].x += particles[i].vx * dT;
		particles[i].y += particles[i].vy * dT;
	}
}
