#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <vector>
#include <iostream>
#include <QApplication>
#include <QThread>
#include <signal.h>
#include <QObject>
#include <QFrame>
#include "smm/charts/chart.hpp"
#include "smm/groundmath.h"
#include "gui/particlesystemwindow.hpp"
#include "gui/generalparametrs.h"
#include <QtCharts>

#define SHADER_TIME_SPEED 550000.f

using std::vector;
using namespace sf;


int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	GeneralParametrs paramWindow;
	paramWindow.move(400, 175);
	paramWindow.show();
	SmmParametrs *params = paramWindow.getParams();
	a.exec();

	QApplication b(argc, argv);
	QFrame* MainFrame = new QFrame;
	MainFrame->setWindowTitle("Particle system v");
	MainFrame->resize(1300, 800);
	MainFrame->show();
	qDebug() << "starting simulation with next parameters:\n"
		   << "b = " << params->b << "\navg creation time = " << params->avgCreationTime
		   << "\nqueue capacity = " << params->queueSize
		   << "\nfacility capacity = " << params->facilitySize;
	ParticleSystemWindow *window = new ParticleSystemWindow(MainFrame, QPoint(10, 10), QSize(1300, 800),
															*params);

	window->update();
	window->show();
	return b.exec();
}
