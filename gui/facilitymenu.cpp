#include "facilitymenu.hpp"
#include "ui_facilitymenu.h"

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
