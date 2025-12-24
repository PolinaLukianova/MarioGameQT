#include "qt_game_map.hpp"
#include <QApplication>
#include <algorithm>

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width, QWidget* parent)
	: QWidget(parent), GameMap(height, width) {
	setFixedSize(width * CELL_SIZE, height * CELL_SIZE);
	setFocusPolicy(Qt::StrongFocus);
	setWindowTitle("Super Mario Game");
}

QtGameMap::~QtGameMap() {
	objs.clear();
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {}

void QtGameMap::refresh() noexcept {
	update();
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(
		std::remove(objs.begin(), objs.end(), obj),
		objs.end()
	);
}

void QtGameMap::remove_objs() {
	objs.clear();
}

void QtGameMap::show() const noexcept {
	const_cast<QtGameMap*>(this)->setVisible(true);
	const_cast<QtGameMap*>(this)->update();
	QApplication::processEvents();
}

void QtGameMap::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::cyan);
    
    painter.scale(CELL_SIZE, CELL_SIZE);
    
    painter.fillRect(0, GameMap::height - 3, GameMap::width, 3, Qt::blue);
    
    for (const auto& obj : objs) {
        if (obj->is_active()) {
            painter.save();
            obj->paint(&painter);
            painter.restore();
        }
    }
}

void QtGameMap::keyPressEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		pressed_keys.insert(event->key());
	}
	QWidget::keyPressEvent(event);
}

void QtGameMap::keyReleaseEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		pressed_keys.remove(event->key());
	}
	QWidget::keyReleaseEvent(event);
}

biv::os::UserInput QtGameMap::get_input() {
	QApplication::processEvents();
	
	if (pressed_keys.contains(Qt::Key_Escape)) {
		return biv::os::UserInput::EXIT;
	}
	if (pressed_keys.contains(Qt::Key_Left) || pressed_keys.contains(Qt::Key_A)) {
		return biv::os::UserInput::MAP_LEFT;
	}
	if (pressed_keys.contains(Qt::Key_Right) || pressed_keys.contains(Qt::Key_D)) {
		return biv::os::UserInput::MAP_RIGHT;
	}
	if (pressed_keys.contains(Qt::Key_Space) || pressed_keys.contains(Qt::Key_Up) || pressed_keys.contains(Qt::Key_W)) {
		return biv::os::UserInput::MARIO_JUMP;
	}
	
	return biv::os::UserInput::NO_INPUT;
}