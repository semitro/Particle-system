#ifndef PARTICLESYSTEMWINDOW_HPP
#define PARTICLESYSTEMWINDOW_HPP

#include "gui/qsfmlintegration.hpp"

#include <SFML/Graphics.hpp>
#include <QtWidgets>

#include "particle-system/core/particlesystem.hpp"
#include "particle-system/graphics/particlesdrawer.hpp"
#include "particle-system/core/circleemitter.hpp"
#include "particle-system/core/newtonlaw.hpp"
#include "particle-system/core/attractor.hpp"
#include "particle-system/core/basicattractor.hpp"

#define WORLD_TIME_SPEED 950000.f

// intgrate qt and sfml
class ParticleSystemWindow : public QSFMLCanvas
{
public:
	~ParticleSystemWindow();
	ParticleSystemWindow(QWidget* parent, const QPoint& position, const QSize& size);

private:
	vector<Attractor*> *attractors;
	ParticleSystem *particleSystem;
	ParticlesDrawer *particleDrawer;
	Clock clock;
	float time;

	virtual void OnInit();
	virtual void OnUpdate();
};

#endif // PARTICLESYSTEMWINDOW_HPP
