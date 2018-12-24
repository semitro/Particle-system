#ifndef GENERALPARAMETRS_H
#define GENERALPARAMETRS_H

#include <QDockWidget>
#include "smm/groundmath.h"

namespace Ui {
class GeneralParametrs;
}

class GeneralParametrs : public QDockWidget
{
	Q_OBJECT

public:
	explicit GeneralParametrs(QWidget *parent = nullptr);
	~GeneralParametrs();

	SmmParametrs *getParams() const;

private slots:
	void on_pushButton_pressed();

	void on_facility_size_valueChanged(int arg1);

	void on_queue_size_valueChanged(int arg1);

	void on_facility_b_valueChanged(double arg1);

	void on_particlesToGen_valueChanged(int arg1);

	void on_avgCreationTime_valueChanged(double arg1);

	void on_comboBox_currentIndexChanged(int index);

	void on_facility_law_currentIndexChanged(int index);

private:
	SmmParametrs *params;

	Ui::GeneralParametrs *ui;
};

#endif // GENERALPARAMETRS_H
