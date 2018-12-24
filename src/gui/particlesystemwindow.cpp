#include "gui/particlesystemwindow.hpp"

ParticleSystemWindow::~ParticleSystemWindow(){}
ParticleSystemWindow::ParticleSystemWindow(QWidget* parent, const QPoint& position,
										   const QSize &size,
										   SmmParametrs params)
	: QSFMLCanvas(parent, position, size)
{

	emitter  = new DotEmitter(10, 10, params.avgCreationTime, params.maxParticles);
	facility = new Facility(600, 400, params.facilitySize, params.b, DISTRIBUTION_LAW::DET);
	queue    = new SmmQueue(200, 200, params.queueSize, facility);
	dustMan  = new DustMan(1500, 1200);
	QFrame *newStage = new QFrame;
	newStage->move(10, 10);
	newStage->resize(1200, 500);
	resultsWindow = new ResultsWindow(newStage, queue, facility);
}

void ParticleSystemWindow::OnInit(){
	this->attractors = new vector<Attractor*>();
	attractors->push_back(dustMan); // order is important
	attractors->push_back(facility);
	attractors->push_back(queue);
	this->particleSystem = new ParticleSystem (emitter, new ParticleLaw(&newtonLaw), attractors);
	this->particleDrawer = new ParticlesDrawer(particleSystem->getParticles());
	this->time = 0.f;
	clock.restart();
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
//	qDebug() << "Update charts..";
	resultsWindow->update(time);
}
