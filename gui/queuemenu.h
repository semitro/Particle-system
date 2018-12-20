#ifndef QUEUEMENU_H
#define QUEUEMENU_H

#include <QDockWidget>

namespace Ui {
class QueueMenu;
}

class QueueMenu : public QDockWidget
{
	Q_OBJECT

public:
	explicit QueueMenu(QWidget *parent = nullptr);
	~QueueMenu();

private:
	Ui::QueueMenu *ui;
};

#endif // QUEUEMENU_H
