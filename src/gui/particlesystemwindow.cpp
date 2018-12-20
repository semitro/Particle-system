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
		// Process events
	Int64 dTime = clock.getElapsedTime().asMicroseconds();
	time += dTime;
	clock.restart();
	RenderWindow::clear(Color(250, 25, 25));
	particleSystem->update(dTime/WORLD_TIME_SPEED);
	particleDrawer->drawPaticles(*this, time);
}
