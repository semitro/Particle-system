#include "generalparametrs.h"
#include "ui_generalparametrs.h"

GeneralParametrs::GeneralParametrs(QWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::GeneralParametrs)
{
	ui->setupUi(this);
}

GeneralParametrs::~GeneralParametrs()
{
	delete ui;
}

void GeneralParametrs::on_pushButton_pressed()
{
	((QApplication*)this->parent())->exit(0);
	this->close();
}
