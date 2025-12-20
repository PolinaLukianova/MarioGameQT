#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
    class JumpingEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
        private:
            int jump_counter = 0;
            static constexpr int JUMP_INTERVAL = 60;
            bool is_on_ground = false;
            float jump_direction = 1.0f;
            Rect* current_platform = nullptr;

        public:
            JumpingEnemy(const Coord& top_left, const int width, const int height);

            Rect get_rect() const noexcept override;
            Speed get_speed() const noexcept override;

            void process_horizontal_static_collision(Rect*) noexcept override;
            void process_mario_collision(Collisionable*) noexcept override;
            void process_vertical_static_collision(Rect*) noexcept override;
            
            void move_horizontally() noexcept override;
            void move_vertically() noexcept override;
            
        private:
            void try_jump() noexcept;
            bool check_platform_ahead() noexcept;
    };
}