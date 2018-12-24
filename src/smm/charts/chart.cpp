#include "smm/charts/chart.hpp"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
	QChart(QChart::ChartTypeCartesian, parent, wFlags),
	m_series(0),
	m_axis(new QValueAxis),
	m_step(0),
	max_x(1),
	min_x(0),
	min_y(0),
	max_y(1)
{

	m_series = new QSplineSeries(this);
	QPen green(Qt::red);
	green.setWidth(3);
	m_series->setPen(green);

	addSeries(m_series);
	createDefaultAxes();
	setAxisX(m_axis, m_series);
	m_axis->setTickCount(5);
	axisX()->setRange(0, 10);
	axisY()->setRange(-5, 10);
	legend()->hide();

//	m_timer.start();
}

Chart::~Chart()
{

}

void Chart::addValue(qreal x, qreal y)
{

	max_x = MAX(max_x, x);
	min_x = MIN(min_x, x);
	max_y = MAX(max_y, y);
	min_y = MIN(min_y, y);

	m_series->append(x, y);
	axisX()->setRange(min_x, max_x);
	axisY()->setRange(min_y, max_y);
}
