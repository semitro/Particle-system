#ifndef GENERALPARAMETRS_H
#define GENERALPARAMETRS_H

#include <QDockWidget>

namespace Ui {
class GeneralParametrs;
}

class GeneralParametrs : public QDockWidget
{
	Q_OBJECT

public:
	explicit GeneralParametrs(QWidget *parent = nullptr);
	~GeneralParametrs();

private slots:
	void on_pushButton_pressed();

private:
	Ui::GeneralParametrs *ui;
};

#endif // GENERALPARAMETRS_H
