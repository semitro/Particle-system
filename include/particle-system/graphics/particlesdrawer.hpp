#ifndef PARTICLESDRAWER_HPP
#define PARTICLESDRAWER_HPP

#include "particle-system/core/particle.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace  sf;
using std::vector;

static Vertex vertexPrototype(Vector2f(0,0), Color(120, 150, 120, 128)); // used to create new vertexes

class ParticlesDrawer
{
public:
    ParticlesDrawer(const vector<Particle> * const particles);
    void drawPaticles(RenderTarget &window, float time);
private:
    const vector<Particle> * const particles;
    VertexArray *vertexes;
    void paricleToVertexes() const;
    Texture background;
    Shader glowShader;
    RenderStates renderStates;
    RenderTexture preRendered; // used to mix up light
};

#endif // PARTICLESDRAWER_HPP
