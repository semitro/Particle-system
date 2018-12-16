#include "particle-system/core/circleemitter.hpp"


CircleEmitter::CircleEmitter(float posX, float posY, std::size_t emissionSize):
	Emitter(posX, posY),
	emissionSize(emissionSize)
{

}

CircleEmitter::~CircleEmitter()
{

}

vector<Particle> CircleEmitter::emit(float deltaTime)
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
		p[i].vx = 0.5f*((rand()/(float)RAND_MAX) - 0.5f);
		p[i].vy = 0.5f*((rand()/(float)RAND_MAX) - 0.5f);
  }
  return p;
}

