#ifndef SMMQUEUE_HPP
#define SMMQUEUE_HPP

#include "particle-system/core/retainingattractor.hpp"

class SmmQueue : public RetainingAttractor{
public:
	SmmQueue(size_t capacity, float x, float y);
};

#endif // SMMQUEUE_HPP
