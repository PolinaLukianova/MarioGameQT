#include "flying_enemy.hpp"
#include "map_movable.hpp"
#include "rect_map_movable_adapter.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height,
                         float minX, float maxX) 
    : RectMapMovableAdapter(top_left, width, height), 
      min_x(minX), max_x(maxX) {
    vspeed = 0;
    hspeed = 0.3;
}

biv::Rect FlyingEnemy::get_rect() const noexcept {
    return {top_left, width, height};
}

biv::Speed FlyingEnemy::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
    change_direction();
}

void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
    mario->kill();
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {}

void FlyingEnemy::move_horizontally() noexcept {
    if (is_at_boundary()) {
        change_direction();
    }
    
    if (moving_right) {
        top_left.x += hspeed;
    } else {
        top_left.x -= hspeed;
    }
}

void FlyingEnemy::move_vertically() noexcept {}

void FlyingEnemy::move_map_left() noexcept {
    RectMapMovableAdapter::move_map_left();
    
    min_x -= MapMovable::MAP_STEP;
    max_x -= MapMovable::MAP_STEP;
}

void FlyingEnemy::move_map_right() noexcept {
    RectMapMovableAdapter::move_map_right();
    
    min_x += MapMovable::MAP_STEP;
    max_x += MapMovable::MAP_STEP;
}

void FlyingEnemy::change_direction() noexcept {
    moving_right = !moving_right;
}

bool FlyingEnemy::is_at_boundary() const noexcept {
    if (moving_right) {
        return top_left.x + hspeed >= max_x;
    } else {
        return top_left.x - hspeed <= min_x;
    }
}
