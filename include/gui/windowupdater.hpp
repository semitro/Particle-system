#ifndef WINDOWUPDATER_HPP
#define WINDOWUPDATER_HPP

#include <QFrame>
#include <QWidget>
#include <QObject>
#include <QTimer>

class WindowUpdater : public QFrame{
	Q_OBJECT
public:
	WindowUpdater(int time, QObject *parent, QWidget *window);
private:
	QWidget *window;

public slots:
	void doUpdate();
};

#endif // WINDOWUPDATER_HPP
