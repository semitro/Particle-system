#include "gui/particlesystemwindow.hpp"

ParticleSystemWindow::~ParticleSystemWindow(){}
ParticleSystemWindow::ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize &size)
	: QSFMLCanvas(parent, position, size)
	{

	}

void ParticleSystemWindow::OnInit(){
}

void ParticleSystemWindow::OnUpdate(){
	this->clear();
	this->display();
}
