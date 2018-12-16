#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "particle-system/graphics/particlesystem.hpp"
#include "particle-system/core/oneoffemitter.hpp"

using namespace sf;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	VertexArray a;
	a.setPrimitiveType(PrimitiveType::Points);
	a.append(*new Vertex(*new Vector2f(10, 10)));
	ParticleSystem pSys(new OneOffEmitter(100));

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
		// Draw the sprite
		// Draw the string
		window.draw(*pSys.getVertexes());
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
