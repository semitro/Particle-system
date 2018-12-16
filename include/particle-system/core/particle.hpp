#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle
{
	Particle(float x, float y) :x(x), y(y){
	}
	float x,y, vx, vy;
};

#endif // PARTICLE_H
