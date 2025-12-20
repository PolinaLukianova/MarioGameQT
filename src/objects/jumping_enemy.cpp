#include "jumping_enemy.hpp"
#include "map_movable.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height) 
    : RectMapMovableAdapter(top_left, width, height) {
    vspeed = 0;
    hspeed = 0;
}

biv::Rect JumpingEnemy::get_rect() const noexcept {
    return {top_left, width, height};
}

biv::Speed JumpingEnemy::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void JumpingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
    jump_direction = -jump_direction;
    hspeed = 0;
}

void JumpingEnemy::process_mario_collision(Collisionable* mario) noexcept {
    if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
        kill();
    } else {
        mario->kill();
    }
}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
    current_platform = obj;
    
    if (vspeed > 0) {
        top_left.y -= vspeed;
        vspeed = 0;
        is_on_ground = true;
        hspeed = 0;
    }
}

void JumpingEnemy::move_horizontally() noexcept {
    if (hspeed != 0) {
        top_left.x += hspeed;
    }
}

void JumpingEnemy::move_vertically() noexcept {
    try_jump();
    
    if (vspeed < MAX_V_SPEED) {
        vspeed += V_ACCELERATION;
    }
    top_left.y += vspeed;
    
    if (vspeed != 0) {
        is_on_ground = false;
    }
}

bool JumpingEnemy::check_platform_ahead() noexcept {
    if (current_platform == nullptr) {
        return false;
    }
    
    const float jump_distance = 4.0f;
    float future_x = top_left.x + jump_direction * jump_distance;
    
    float future_center = future_x + width / 2.0f;
    
    bool will_be_on_platform = (
        future_center > current_platform->get_left() &&
        future_center < current_platform->get_right()
    );
    
    return will_be_on_platform;
}

void JumpingEnemy::try_jump() noexcept {
    jump_counter++;
    
    if (is_on_ground && jump_counter >= JUMP_INTERVAL) {
        if (!check_platform_ahead()) {
            jump_direction = -jump_direction;
        }
        
        if (check_platform_ahead()) {
            vspeed = JUMP_SPEED * 0.7f;
            hspeed = 0.15f * jump_direction;
            is_on_ground = false;
            jump_counter = 0;
        } else {
            jump_counter = JUMP_INTERVAL - 10;
        }
    }
}