#include "particle-system/core/dotemitter.hpp"


DotEmitter::DotEmitter(float posX, float posY, float mTime):
	Emitter(posX, posY), mTime(mTime)
{

}

DotEmitter::~DotEmitter()
{

}

vector<Particle> DotEmitter::emit(float deltaTime)
{
	static int x = 0;
	x++;
	this->nextEmissionTime -= deltaTime;

	if(nextEmissionTime <= 0.f && x < 2){
		nextEmissionTime = this->mTime;
		vector<Particle> p(1);
		p[0].x  = this->x;
		p[0].y  = this->y;
		return p;
	}
	else{
		vector<Particle> p(0); // empty one
		return p;
	}
}
