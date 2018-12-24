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
	max_x(10),
	min_x(0),
	min_y(0),
	max_y(10)
{
	QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
	m_timer.setInterval(1000);

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

void Chart::addValue(qreal m_x, qreal m_y)
{

	max_x = MAX(max_x, m_x);
	min_x = MIN(min_x, m_x);
	max_y = MAX(max_y, m_y);
	min_y = MIN(min_y, m_y);

	m_series->append(m_x, m_y);
	axisX()->setRange(min_x, max_x);
	axisY()->setRange(min_y, max_y);
}

void Chart::handleTimeout()
{
	return ;
}
