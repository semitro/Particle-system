#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include "particle-system/graphics/particlesystem.hpp"
#include "particle-system/core/circleemitter.hpp"
#include "particle-system/core/newtonlaw.hpp"

using namespace sf;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	VertexArray a;
	a.setPrimitiveType(PrimitiveType::Points);
	a.append(*new Vertex(*new Vector2f(10, 10)));
	ParticleSystem pSys(new CircleEmitter(200, 200, 1), new ParticleLaw(&newtonLaw));
	Texture texture;
	texture.loadFromFile("textures/gradient.png");
	RenderStates renderStates;
	sf::Shader shader;
	shader.loadFromFile("shaders/shader.frag", Shader::Fragment);
	shader.setUniform("texture", Shader::CurrentTexture);
	renderStates.texture = &texture;
	renderStates.shader = &shader;

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
		pSys.update(0.02f);
//		window.draw(Sprite(texture), renderStates );
		window.draw(*pSys.getVertexes(), renderStates);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}
