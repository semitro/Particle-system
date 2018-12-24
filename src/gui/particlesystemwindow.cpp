#include "gui/particlesystemwindow.hpp"

ParticleSystemWindow::~ParticleSystemWindow(){}
ParticleSystemWindow::ParticleSystemWindow(QWidget* parent, const QPoint& position,
										   const QSize &size,
										   SmmParametrs params)
	: QSFMLCanvas(parent, position, size)
{

	facility = new Facility(600, 400, params.facilitySize, params.b, DISTRIBUTION_LAW::DET);
	queue = new SmmQueue(300, 300, params.queueSize, facility);
	emitter = new DotEmitter(50, 400, params.avgCreationTime, params.maxParticles);
}

void ParticleSystemWindow::OnInit(){

	this->queueChart = new Chart;
	this->queueChartView = new QChartView(queueChart);
	queueChartView->setRenderHint(QPainter::Antialiasing);
//	queueChartView->show();

	this->particleChart = new Chart;
	this->particleChartView = new QChartView(particleChart);

	this->facilityChart = new Chart;
	this->facilityChartView = new QChartView(facilityChart);
	facilityChartView->setGeometry(500, 500, 100, 100);
	facilityChartView->show();

//	particleChartView->show();

	this->attractors = new vector<Attractor*>();
	attractors->push_back(facility);
//	attractors->push_back(queue);
	this->particleSystem = new ParticleSystem( emitter, new ParticleLaw(&newtonLaw), attractors);
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
	particleChart->addValue(time, particleSystem->getParticles()->size());
	facilityChart->addValue(time, this->facility->getTransactsNumber());
	queueChart->addValue(time, queue->getTransactsNumber());

}
