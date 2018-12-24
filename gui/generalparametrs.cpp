#include "generalparametrs.h"
#include "ui_generalparametrs.h"
#include <QDebug>

GeneralParametrs::GeneralParametrs(QWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::GeneralParametrs)
{
	params = new SmmParametrs;
	ui->setupUi(this);
	params->avgCreationTime = 1.f;
	params->b = 1.f;
	params->facilitySize = 1;
	params->maxParticles = 100;
	params->queueSize = 1;
	params->creationLaw = DET;
	params->facilityLaw = DET;
}

GeneralParametrs::~GeneralParametrs()
{
	delete ui;
	qDebug() << "params destructor";
}

void GeneralParametrs::on_pushButton_pressed()
{
	((QApplication*)this->parent())->exit(0);
	this->close();
}


void GeneralParametrs::on_facility_size_valueChanged(int arg1)
{
   this->params->facilitySize = arg1;
}

void GeneralParametrs::on_queue_size_valueChanged(int arg1)
{
   this->params->queueSize = arg1;
}

void GeneralParametrs::on_facility_b_valueChanged(double arg1)
{
   this->params->b = arg1;
}

void GeneralParametrs::on_particlesToGen_valueChanged(int arg1)
{
   this->params->maxParticles = arg1;
}

void GeneralParametrs::on_avgCreationTime_valueChanged(double arg1)
{
   this->params->avgCreationTime = arg1;
}

SmmParametrs *GeneralParametrs::getParams() const
{
	return params;
}

