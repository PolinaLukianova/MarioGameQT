#pragma once

#include "qt_ui_obj.hpp"
#include "rect.hpp"

namespace biv {
    class QtUIObjectRectAdapter : public virtual QtUIObject, public virtual Rect {
        public:
            QtUIObjectRectAdapter(
                const Coord& top_left, const int width, const int height
            );
            
            int get_bottom() const noexcept override;
            int get_height() const noexcept override;
            int get_left() const noexcept override;
            int get_right() const noexcept override;
            int get_top() const noexcept override;
            
            void draw(QPainter* painter) const override;
            
            bool is_active() const noexcept override;
            void paint(QPainter* painter) override;
            
            int get_width() const noexcept override;
    };
}