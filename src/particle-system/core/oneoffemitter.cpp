#include "particle-system/core/oneoffemitter.hpp"


OneOffEmitter::OneOffEmitter(float x, float y, float emissionSize):
	Emitter(x, y),
	emitted(false), emissionSize(emissionSize)
{

}

OneOffEmitter::~OneOffEmitter()
{

}

vector<Particle> OneOffEmitter::emit(float currentTime)
{

	if(emitted){
		vector<Particle> p(0);
		return p;
	}
	emitted = true;
	vector<Particle> p(emissionSize*emissionSize);
	for(size_t i = 0; i < emissionSize; i++){
		for(size_t j = 0; j < emissionSize; j++){
			p[i+j*i].x = i*0.8f + 2*(rand()/RAND_MAX);
			p[i+j*i].y = j*0.8f + 3.5f*(rand()/RAND_MAX);
		}
  }
  return p;
}

