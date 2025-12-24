#pragma once

#include <QPainter>
#include "rect.hpp"

namespace biv {
    class QtUIObject {
        public:
            virtual ~QtUIObject() = default;
            
            virtual int get_bottom() const noexcept = 0;
            virtual QColor get_color() const noexcept = 0;
            virtual int get_height() const noexcept = 0;
            virtual int get_left() const noexcept = 0;
            virtual int get_right() const noexcept = 0;
            virtual int get_top() const noexcept = 0;
            virtual void draw(QPainter* painter) const = 0;
            
            virtual bool is_active() const noexcept = 0;
            virtual void paint(QPainter* painter) = 0;
            
            virtual int get_width() const noexcept = 0;
    };
}