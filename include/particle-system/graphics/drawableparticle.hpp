#ifndef DRAWABLEPARTICLE_HPP
#define DRAWABLEPARTICLE_HPP

#include <SFML/Graphics/VertexArray.hpp>
#include "particle-system/core/particle.hpp"

using namespace sf;

class DrawableParticle : Drawable
{
public:
	DrawableParticle();
private:
	VertexArray arr;

};

#endif // DRAWABLEPARTICLE_HPP
