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
	attractors->push_back(new BasicAttractor(300, 200, 0.005f));

	ParticleSystem pSys(new CircleEmitter(50, 200, 0.01f), new ParticleLaw(&newtonLaw),
						attractors);

    Vector2f iResolution(VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height);
	Texture texture;
	texture.loadFromFile("textures/gradient.png");
	RenderStates renderStates;
	sf::Shader shader;
	shader.loadFromFile("shaders/shader.frag", Shader::Fragment);
	shader.setUniform("texture", Shader::CurrentTexture);
    shader.setUniform("iResolution", iResolution);

	renderStates.texture = &texture;
	renderStates.shader = &shader;
    cout << VideoMode::getDesktopMode().width << "\n";

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
		window.clear();
        pSys.update(0.002f);
//		window.draw(Sprite(texture), renderStates );
		window.draw(*pSys.getVertexes(), renderStates);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
