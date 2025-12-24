#include "qt_flying_enemy.hpp"

using biv::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(
	const Coord& top_left, const int width, const int height,
	float minX, float maxX
) : FlyingEnemy(top_left, width, height, minX, maxX),
	QtUIObjectRectAdapter(top_left, width, height) {}

QColor QtFlyingEnemy::get_color() const noexcept {
	return Qt::darkCyan;
}