#ifndef PARTICLESYSTEMWINDOW_HPP
#define PARTICLESYSTEMWINDOW_HPP

#include "gui/qsfmlintegration.hpp"

#include <SFML/Graphics.hpp>
#include <QtWidgets>

// intgrate qt and sfml
class ParticleSystemWindow : public QSFMLCanvas
{
public:
	~ParticleSystemWindow();
	ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize& size);

private:

	virtual void OnInit();

	virtual void OnUpdate();
};

#endif // PARTICLESYSTEMWINDOW_HPP
