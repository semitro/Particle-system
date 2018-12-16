#include "particle-system/core/particlelaw.hpp"

ParticleLaw::ParticleLaw(void law(vector<Particle> &)):law(law)
{
}

void ParticleLaw::process(vector<Particle> &p)
{
		law(p);
}
