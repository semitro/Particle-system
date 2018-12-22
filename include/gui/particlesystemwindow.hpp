#ifndef PARTICLESYSTEMWINDOW_HPP
#define PARTICLESYSTEMWINDOW_HPP

#include "gui/qsfmlintegration.hpp"

#include <SFML/Graphics.hpp>
#include <QtWidgets>

#include "particle-system/core/particlesystem.hpp"
#include "particle-system/graphics/particlesdrawer.hpp"
#include "particle-system/core/dotemitter.hpp"
#include "particle-system/core/newtonlaw.hpp"
#include "particle-system/core/attractor.hpp"
#include "smm/facility.hpp"
#include "smm/smmqueue.hpp"
#include "gui/facilitymenu.h"

#define WORLD_TIME_SPEED 10.f


// intgrate qt and sfml
class ParticleSystemWindow : public QSFMLCanvas
{
public:
	~ParticleSystemWindow();
	ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize& size);
protected:
	void mousePressEvent(QMouseEvent *);
private:
	vector<Attractor*> *attractors;
	ParticleSystem *particleSystem;
	ParticlesDrawer *particleDrawer;
	Clock clock;
	QTimer timer;
	float time;
	FacilityMenu *facilityMenu;
	virtual void OnInit();
	virtual void OnUpdate();
private slots:
	void onTimeOut();
};

#endif // PARTICLESYSTEMWINDOW_HPP
