#include "queuemenu.h"
#include "ui_queuemenu.h"

QueueMenu::QueueMenu(QWidget *parent) :
	QDockWidget(parent),
	ui(new Ui::QueueMenu)
{
	ui->setupUi(this);
}

QueueMenu::~QueueMenu()
{
	delete ui;
}
