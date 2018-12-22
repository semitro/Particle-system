#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{
	Particle(float x, float y)
		: x(x), y(y), vx(0), vy(0),
		  id(counter++)
	{
	}
	Particle() : Particle(0, 0){
	}

	float x, y, vx, vy;
	unsigned long id;
	static unsigned long counter;
};


#endif // PARTICLE_H

