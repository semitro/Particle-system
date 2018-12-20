#ifndef Q_SFML_INTEGRATION_HPP
#define Q_SFML_INTEGRATION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <QtWidgets>
#include <QTimer>

// intgrate qt and sfml
class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:

	QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);

	virtual ~QSFMLCanvas();

private:

	virtual void OnInit()=0;

	virtual void OnUpdate()=0;

	virtual QPaintEngine* paintEngine() const;

	virtual void showEvent(QShowEvent*);

	virtual void paintEvent(QPaintEvent*);

	QTimer myTimer;
	bool   myInitialized;
};

#endif // PARTICLESYSTEMWINDOW_HPP
