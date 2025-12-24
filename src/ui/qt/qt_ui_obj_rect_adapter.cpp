#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtUIObjectRectAdapter;

QtUIObjectRectAdapter::QtUIObjectRectAdapter(
    const Coord& top_left, const int width, const int height
) : Rect(top_left, width, height) {}

int QtUIObjectRectAdapter::get_bottom() const noexcept {
    return Rect::get_bottom();
}

int QtUIObjectRectAdapter::get_height() const noexcept {
    return Rect::get_height();
}

int QtUIObjectRectAdapter::get_left() const noexcept {
    return Rect::get_left();
}

int QtUIObjectRectAdapter::get_right() const noexcept {
    return Rect::get_right();
}

int QtUIObjectRectAdapter::get_top() const noexcept {
    return Rect::get_top();
}

void QtUIObjectRectAdapter::draw(QPainter* painter) const {
    painter->fillRect(
        get_left(),
        get_top(), 
        get_width(),
        get_height(),
        get_color()
    );
}

bool QtUIObjectRectAdapter::is_active() const noexcept {
    return true;
}

void QtUIObjectRectAdapter::paint(QPainter* painter) {
    draw(painter);
}

int QtUIObjectRectAdapter::get_width() const noexcept {
    return width;
}