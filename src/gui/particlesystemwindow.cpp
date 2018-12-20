#include "gui/particlesystemwindow.hpp"

ParticleSystemWindow::~ParticleSystemWindow(){}
ParticleSystemWindow::ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize &size)
	: QSFMLCanvas(parent, position, size)
{

}

void ParticleSystemWindow::OnInit(){
	this->attractors = new vector<Attractor*>();
	attractors->push_back(new BasicAttractor(700, 400, 0.005f));
	this->particleSystem = new ParticleSystem(new CircleEmitter(50, 200, 0.001f), new ParticleLaw(&newtonLaw),
						attractors);
	this->particleDrawer = new ParticlesDrawer(particleSystem->getParticles());

	this->time = 0.f;
}

void ParticleSystemWindow::OnUpdate(){
	this->clear();
		// Process events
	sf::Event event;
	while (this->pollEvent(event))
	{
			// Close window: exit
		if (event.type == sf::Event::Closed)
			this->RenderWindow::close();
		}
		// Clear screen
	Int64 dTime = clock.getElapsedTime().asMicroseconds();
	time += dTime;
	clock.restart();
	particleSystem->update(dTime/WORLD_TIME_SPEED);
	this->clear();
	particleDrawer->drawPaticles(*this, time);
	this->display();
}
