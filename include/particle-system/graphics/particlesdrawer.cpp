#include "particlesdrawer.hpp"

ParticlesDrawer::ParticlesDrawer(const vector<Particle> * const particles)
    :particles(particles), glowShader(), renderStates(&glowShader)
{
    this->vertexes = new VertexArray(PrimitiveType::Points, particles->size());
    background.loadFromFile("textures/gradient.png");
    renderStates.texture = &background;

    Vector2f iResolution(VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height);

    preRendered.create(iResolution.x, iResolution.y);
    glowShader.loadFromFile("shaders/shader.frag", Shader::Fragment);
    glowShader.setUniform("texture", background);
    glowShader.setUniform("iResolution", iResolution);


}

void ParticlesDrawer::drawPaticles(RenderTarget &window, float time){
    this->paricleToVertexes();

    preRendered.clear();
    preRendered.draw(*vertexes); // to a temporary texture
    preRendered.display();

    glowShader.setUniform("baseTexture", preRendered.getTexture());
    glowShader.setUniform("uTime", time/500.f);//SHADER_TIME_SPEED);

    window.draw(*new Sprite(preRendered.getTexture()), renderStates);

}

void ParticlesDrawer::paricleToVertexes() const{
    if(vertexes->getVertexCount() < particles->size()) // add particles that appeared
        for(size_t i = 0; i < particles->size() - vertexes->getVertexCount(); i++)
            vertexes->append(vertexPrototype);


    for(size_t i = 0; i < particles->size(); i++){
        (*vertexes)[i].position.x = (*particles)[i].x;
        (*vertexes)[i].position.y = (*particles)[i].y;
    }
}
