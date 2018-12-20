#include "facilitymenu.h"
#include "ui_facilitymenu.h"

FacilityMenu::FacilityMenu(QWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::FacilityMenu)
{
	ui->setupUi(this);
}

FacilityMenu::~FacilityMenu()
{
	delete ui;
}

void FacilityMenu::on_pushButton_clicked()
{

}
