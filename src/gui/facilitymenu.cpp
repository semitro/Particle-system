#include "gui/facilitymenu.hpp"

facilityMenu::facilityMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::facilityMenu)
{
	ui->setupUi(this);
}

facilityMenu::~facilityMenu()
{
	delete ui;
}
