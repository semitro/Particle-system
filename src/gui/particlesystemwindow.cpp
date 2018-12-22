#include "gui/particlesystemwindow.hpp"

ParticleSystemWindow::~ParticleSystemWindow(){}
ParticleSystemWindow::ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize &size)
	: QSFMLCanvas(parent, position, size)
{

//	facilityMenu = new FacilityMenu(this);
}

void ParticleSystemWindow::OnInit(){
	this->attractors = new vector<Attractor*>();
	Facility *facility = new Facility(600, 400, 20, 2.5f, DISTRIBUTION_LAW::DET);
//	attractors->push_back(facility);
	attractors->push_back(new SmmQueue(300, 300, 20, facility));
	this->particleSystem = new ParticleSystem(new DotEmitter(50, 400, 0.001f),
											  new ParticleLaw(&newtonLaw),
						attractors);
	this->particleDrawer = new ParticlesDrawer(particleSystem->getParticles());
	this->time = 0.f;


}

void ParticleSystemWindow::mousePressEvent ( QMouseEvent * event ){
//	facilityMenu->show();
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
