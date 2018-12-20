#ifndef FACILITYMENU_HPP
#define FACILITYMENU_HPP

#include <QWidget>

namespace Ui {
class facilityMenu;
}

class facilityMenu : public QWidget
{
	Q_OBJECT

public:
	explicit facilityMenu(QWidget *parent = nullptr);
	~facilityMenu();

private:
	Ui::facilityMenu *ui;
};

#endif // FACILITYMENU_HPP
