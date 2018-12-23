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
#include "gui/particlesystemwindow.hpp"
#include <QtCharts>

#define SHADER_TIME_SPEED 550000.f

using std::vector;
using namespace sf;


int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	QFrame* MainFrame = new QFrame;
	MainFrame->setWindowTitle("Particle system v");
	MainFrame->resize(1300, 800);
	MainFrame->show();
	ParticleSystemWindow *window = new ParticleSystemWindow(MainFrame,  QPoint(10, 10), QSize(1300, 800));

	window->update();
	window->show();
	return a.exec();
}
