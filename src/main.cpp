#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "particle-system/graphics/particlesystem.hpp"
#include "particle-system/core/circleemitter.hpp"
#include "particle-system/core/newtonlaw.hpp"
#include "particle-system/core/attractor.hpp"
#include "particle-system/core/basicattractor.hpp"
#include <vector>
#include <iostream>

#define WORLD_TIME_SPEED 950000.f
#define SHADER_TIME_SPEED 550000.f

using std::vector;
using namespace sf;
using std::cout;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	VertexArray a;
	a.setPrimitiveType(PrimitiveType::Points);
	a.append(*new Vertex(*new Vector2f(10, 10)));

	vector<Attractor*> *attractors = new vector<Attractor*>();
    attractors->push_back(new BasicAttractor(700, 400, 0.005f));

    ParticleSystem pSys(new CircleEmitter(50, 200, 0.001f), new ParticleLaw(&newtonLaw),
						attractors);

    Vector2f iResolution(VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height);
	Texture texture;
	texture.loadFromFile("textures/gradient.png");
    Texture particleTexture;
    particleTexture.loadFromFile("textures/particle.png");
    RenderStates particleRenderState(&particleTexture);
    Shader shader;
    shader.setUniform("texture", texture);

	shader.loadFromFile("shaders/shader.frag", Shader::Fragment);
    shader.setUniform("texture", texture);
    shader.setUniform("iResolution", iResolution);
    Clock clock;
    float time = 0.f;
    RenderStates renderStates(&shader);
    renderStates.texture = &texture;
    RenderTexture renderedTexture;
    renderedTexture.create(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
        Int64 dTime = clock.getElapsedTime().asMicroseconds();
        time += dTime;
        clock.restart();
        pSys.update(dTime/WORLD_TIME_SPEED);
        renderedTexture.clear();
        CircleShape sh;
        sh.setRadius(1.5f);
        sh.setFillColor(Color(125, 155, 125, 128));

        for(size_t i = 0; i < pSys.getVertexes()->getVertexCount(); i++){
           Vertex dot = (*pSys.getVertexes())[i];
           IntRect ir(0, 0, 5, 5);
           Sprite point(particleTexture);
           point.setPosition(dot.position);
           point.scale(0.5f, 0.5f);
//           renderedTexture.draw(point);
           sh.setPosition(dot.position);
           renderedTexture.draw(sh);

        }
//        renderedTexture.draw(*pSys.getVertexes(), particleRenderState);
        renderedTexture.display();

        shader.setUniform("uTime", time/SHADER_TIME_SPEED);
        shader.setUniform("baseTexture", renderedTexture.getTexture());

        window.clear();
        window.draw(*new Sprite(renderedTexture.getTexture()), renderStates);
//        window.draw(*pSys.getVertexes(), renderStates);


		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}


