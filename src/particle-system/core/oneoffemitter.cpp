#include "particle-system/core/oneoffemitter.hpp"


OneOffEmitter::OneOffEmitter(std::size_t emissionSize):
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
	vector<Particle> p(emissionSize);
	for(size_t i = 0; i < emissionSize; i++){
	  p[i].x = i*0.5f;
	  p[i].y = i*0.25f + rand()/(float)RAND_MAX;
  }
  return p;
}

