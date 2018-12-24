#include "particle-system/core/dotemitter.hpp"


DotEmitter::DotEmitter(float posX, float posY, float mTime, size_t maxEmissions,
					   DISTRIBUTION_LAW distr):
	Emitter(posX, posY), mTime(mTime), maxEmissions(maxEmissions), emitted(0),
	distribution(distr)
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
		nextEmissionTime = calcNextEmission();
		vector<Particle> p(1);
		p[0].x  = this->x;
		p[0].y  = this->y;
		qDebug() << "CREATE PARTICLE";
		return p;
	}
	else{
		vector<Particle> p(0); // empty one
		return p;
	}
}

float DotEmitter::calcNextEmission(){
	if(this->distribution == DISTRIBUTION_LAW::DET)
		return this->mTime;
	else
		return nextExpRand(mTime);
}
