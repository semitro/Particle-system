#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{
	Particle(float x, float y)
		: x(x), y(y), vx(0), vy(0),
		  id(counter++),
		  f1(0.f), f2(0.f), f3(0.f), f4(0.f),
		  p1(0), p2(0), p3(0), p4(0)
	{
	}
	Particle() : Particle(0, 0){
	}

	long  id;
	static long  counter;
	float x, y, vx, vy, f1, f2, f3, f4;
	int p1, p2, p3, p4; // user variables
};


#endif // PARTICLE_H

