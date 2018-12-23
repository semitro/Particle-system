#include "particle-system/core/dotemitter.hpp"


DotEmitter::DotEmitter(float posX, float posY, float mTime, size_t maxEmissions):
	Emitter(posX, posY), mTime(mTime), maxEmissions(maxEmissions), emitted(0)
{

}

DotEmitter::~DotEmitter()
{

}

#include <QDebug>

vector<Particle> DotEmitter::emit(float deltaTime)
{
	this->nextEmissionTime -= deltaTime;
//	qDebug() << "Next emission" << nextEmissionTime;
	if(nextEmissionTime <= 0.f && emitted < maxEmissions){
		emitted++;
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
