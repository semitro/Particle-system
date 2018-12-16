#ifndef NEWTONLAW_HPP
#define NEWTONLAW_HPP

#include <vector>
#include "particle-system/core/particle.hpp"
#include "math.h"

#define G 0.055f
using std::vector;
using std::size_t;

void newtonLaw(vector<Particle> &particles);
#endif // NEWTONLAW_HPP
