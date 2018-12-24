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

	queueAvgTimeChart = new Chart;
	queueAvgTimeChartView = new QChartView(queueAvgTimeChart);
	queueAvgTimeChartView->move(200, 600);
	queueAvgTimeChartView->resize(350, 350);
	queueAvgTimeChart->axisY()->setTitleText("Среднее время ожидания");
	queueAvgTimeChartView->show();
//	this->close();
}

void ResultsWindow::update(float time)
{
	float max_queueing = 0.f;
	float avg_queueing = 0.f;
	float max_cultivating = 0.f;
	float avg_cultivating = 0.f;
	size_t trans_size = 0;
	size_t queue_total = 0;
	for(int i = 0; i < facility->allTheTransacts->size(); i++){
		Transact *t = (*facility->allTheTransacts)[i];
		if(t == nullptr)
			continue;
		trans_size++;
//		if(t->facilityData[0].state == StateInFacility::PROCESSED){
//			avg_cultivating += t->facilityData[0].timeOfBeing;
//			max_cultivating = MAX(t->facilityData[0].timeOfBeing, max_cultivating);
//		}
		if(t->queueData[0].state == StateInQueue::LEAVED
				|| t->queueData[0].state == StateInQueue::QUEUEING){
//			max_queueing = MAX(t->queueData[0].timeOfBeing, max_queueing);
			avg_queueing += t->queueData[0].timeOfBeing;
			queue_total++;
		}
	}
	avg_queueing /= (float)queue_total;

	this->facilityParticlesChart->addValue(time, facility->getTransactsNumber());
	this->queueParticlesChart->addValue(time, queue->getTransactsNumber());
	this->queueAvgTimeChart->addValue(time, avg_queueing);
	qDebug() << "charts updated";
}
