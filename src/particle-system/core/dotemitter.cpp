#include "particle-system/core/dotemitter.hpp"


DotEmitter::DotEmitter(float posX, float posY, float emissionSize):
	Emitter(posX, posY),
	emissionSize(emissionSize)
{

}

DotEmitter::~DotEmitter()
{

}

vector<Particle> DotEmitter::emit(float deltaTime)
{
	static float nextEmission = this->emissionSize;

	nextEmission -= deltaTime;

	if(nextEmission > 0.f){
		vector<Particle> p(0);
		return p;
	}

	nextEmission = this->emissionSize;
	size_t emissionNumber = 1;

	vector<Particle> p(emissionNumber);
	for(size_t i = 0; i < emissionNumber; i++){
		p[i].x  = this->x;
		p[i].y  = this->y;
  }
  return p;
}
