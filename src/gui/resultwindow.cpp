#include "gui/resultwindow.hpp"

ResultsWindow::ResultsWindow(QWidget *Parent,
							 SmmQueue *queue, Facility *facility)
	: QWidget (Parent),
	  queue(queue), facility(facility)
{
	QGridLayout *lay = new QGridLayout();
	lay->setSizeConstraint(QLayout::SetFixedSize);
	this->queueParticlesChart = new Chart;
	this->queueParticlesChartView = new QChartView(queueParticlesChart);
	queueParticlesChart->axisY()->setTitleText("Заявок в очереди");
	queueParticlesChart->axisX()->setTitleText("Время");
	queueParticlesChartView->resize(350, 350);
//	lay->addWidget(queueParticlesChartView, 0, 0);
	this->facilityParticlesChart = new Chart;
	this->facilityParticlesChartView = new QChartView(facilityParticlesChart);
	this->facilityParticlesChart->axisY()->setTitleText("Заявок на обслуживании");
//	this->facilityParticlesChart->axisX()->setTitleText("Время");
	facilityParticlesChartView->resize(350, 350);
	lay->addWidget(facilityParticlesChartView, 0, 1);
//	lay->update();
//	this->setLayout(lay);
//	this->show();
	queueParticlesChartView->show();
	queueParticlesChartView->move(20, 20);
	facilityParticlesChartView->move(500, 200);
	facilityParticlesChartView->show();
	this->close();
	this->hide();
}

void ResultsWindow::update(float time)
{
	this->facilityParticlesChart->addValue(time, facility->getTransactsNumber());
	this->queueParticlesChart->addValue(time, queue->getTransactsNumber());
}
