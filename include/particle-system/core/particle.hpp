#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle
{
	Particle(float x, float y) :x(x), y(y), vx(0), vy(0){
	}
	Particle() :x(0), y(0), vx(0), vy(0){
	}

	float x,y, vx, vy;
};

#endif // PARTICLE_H
