#ifndef PARTICLESYSTEMWINDOW_HPP
#define PARTICLESYSTEMWINDOW_HPP

#include "gui/qsfmlintegration.hpp"

#include <SFML/Graphics.hpp>
#include <QtWidgets>
#include <QtCharts>

#include "particle-system/core/particlesystem.hpp"
#include "particle-system/graphics/particlesdrawer.hpp"
#include "particle-system/core/dotemitter.hpp"
#include "particle-system/core/newtonlaw.hpp"
#include "particle-system/core/attractor.hpp"
#include "smm/facility.hpp"
#include "smm/smmqueue.hpp"
#include "gui/facilitymenu.h"
#include "gui/generalparametrs.h"
#include "smm/charts/chart.hpp"
#include "smm/groundmath.h"
#include "resultwindow.hpp"
#include "smm/dustman.hpp"

#define WORLD_TIME_SPEED 940000.f

// intgrate qt and sfml
class ParticleSystemWindow : public QSFMLCanvas
{
public:
	~ParticleSystemWindow();
	ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize& size,
					SmmParametrs params);
protected:
	void mousePressEvent(QMouseEvent *);
private:
	SmmParametrs params;
	vector<Attractor*> *attractors;

	ParticleSystem *particleSystem;
	ParticlesDrawer *particleDrawer;

	Emitter *emitter;
	SmmQueue *queue;

	Facility *facility;

	DustMan *dustMan;

	Clock clock;
	QTimer timer;
	float time;
	FacilityMenu *facilityMenu;
	virtual void OnInit();
	virtual void OnUpdate();
	ResultsWindow *resultsWindow;
private slots:
	void onTimeOut();
};

#endif // PARTICLESYSTEMWINDOW_HPP
