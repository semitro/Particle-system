#include "gui/windowupdater.hpp"
#include <iostream>
using std::cerr;

void WindowUpdater::doUpdate(){
	cerr << "hello";
}

WindowUpdater::WindowUpdater(int time, QObject *parent, QWidget *window) : window(window){
		QTimer *timer = new QTimer(parent);
		timer->setInterval(time);
		QObject::connect(timer, SIGNAL(timer->timeout()), this, SLOT(this->update()));
}
