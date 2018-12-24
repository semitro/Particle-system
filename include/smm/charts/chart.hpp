#ifndef CHART_HPP
#define CHART_HPP
#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE
#define MAX(A, B) ((A) >= (B) ? (A) : (B) )
#define MIN(A, B) ((A) <= (B) ? (A) : (B) )

class Chart: public QChart
{
	Q_OBJECT
public:
	Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
	virtual ~Chart();
	void addValue(qreal m_x, qreal m_y);
private:
	QSplineSeries *m_series;
	QStringList m_titles;
	QValueAxis *m_axis;
	qreal m_step;
	qreal max_x;
	qreal min_x;
	qreal min_y;
	qreal max_y;
};

#endif // CHART_HPP
