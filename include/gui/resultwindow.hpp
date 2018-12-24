#ifndef RESULTWINDOW_HPP
#define RESULTWINDOW_HPP

#include <QChartView>

#include "qsfmlintegration.hpp"
#include "smm/charts/chart.hpp"
#include "particle-system/core/particlesystem.hpp"
#include "smm/facility.hpp"
#include "smm/smmqueue.hpp"

class ResultsWindow : public QWidget
{
public:
	ResultsWindow(QWidget* Parent, SmmQueue *queue, Facility *facility);
	void update(float currentTime);

private:
	SmmQueue *queue;
	Facility *facility;

	Chart *facilityParticlesChart;
	QChartView *facilityParticlesChartView;
	Chart *queueParticlesChart;
	QChartView *queueParticlesChartView;
};

#endif // RESULTWINDOW_HPP
