#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "particle-system/core/particlesystem.hpp"
#include "particle-system/graphics/particlesdrawer.hpp"

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
    RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	vector<Attractor*> *attractors = new vector<Attractor*>();
    attractors->push_back(new BasicAttractor(700, 400, 0.005f));

    ParticleSystem pSys(new CircleEmitter(50, 200, 0.001f), new ParticleLaw(&newtonLaw),
						attractors);

    ParticlesDrawer particlesDrawer(pSys.getParticles());
    Clock clock;
    float time = 0.f;

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
        window.clear();
        particlesDrawer.drawPaticles(window, time);
        window.display();


	}
	return EXIT_SUCCESS;
}


void render(RenderWindow &window){

    // Update the window
}
