#include "gui/windowupdater.hpp"
#include <iostream>
#include <QtDebug>
using std::cerr;

void WindowUpdater::doUpdate(){
	window->parentWidget()->update();
	window->update();
	window->repaint();
}

WindowUpdater::WindowUpdater(int time, QObject *parent, QWidget *window) : QObject(parent), window(window){
		QTimer *timer = new QTimer(parent);
		timer->setInterval(time);
		timer->setTimerType(Qt::TimerType::CoarseTimer);
		this->connect(timer, &QTimer::timeout, this, &WindowUpdater::doUpdate);
		timer->start();
}
