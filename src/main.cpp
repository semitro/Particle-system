#include <Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <vector>
#include <iostream>
#include <QApplication>
#include <QThread>
#include "gui/particlesystemwindow.hpp"

#define SHADER_TIME_SPEED 550000.f

using std::vector;
using namespace sf;
using std::cout;

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	QFrame* MainFrame = new QFrame;
	MainFrame->setWindowTitle("Qt SFML");
	MainFrame->resize(400, 400);
	MainFrame->show();
	ParticleSystemWindow window(MainFrame,  QPoint(10, 10), QSize(600, 400));
	window.show();
	return a.exec();
}
