#include "particle-system/core/particlelaw.hpp"

ParticleLaw::ParticleLaw(void law(vector<Particle> &, float)):law(law)
{
}

void ParticleLaw::process(vector<Particle> &p, float dT)
{
		law(p, dT);

}
