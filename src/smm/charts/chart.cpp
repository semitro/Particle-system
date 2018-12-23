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
	m_x(5),
	m_y(1)
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

//	m_timer.start();
}

Chart::~Chart()
{

}

void Chart::addValue(qreal m_x, qreal m_y)
{
	static qreal max_x = 10;
	static qreal min_x = 0;
	static qreal min_y = 0;
	static qreal max_y = 10;

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
	qreal x = plotArea().width() / m_axis->tickCount();
	qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
	m_x += y;
	m_y = rand()%5;
	m_series->append(m_x, m_y);
	axisX()->setRange(0, m_x);
	if (m_x == 100)
		m_timer.stop();
}
