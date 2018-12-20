#ifndef FACILITYMENU_H
#define FACILITYMENU_H

#include <QDockWidget>

namespace Ui {
class FacilityMenu;
}

class FacilityMenu : public QDockWidget
{
	Q_OBJECT

public:
	explicit FacilityMenu(QWidget *parent = nullptr);
	~FacilityMenu();

private slots:
	void on_pushButton_clicked();

private:
	Ui::FacilityMenu *ui;
};

#endif // FACILITYMENU_H
