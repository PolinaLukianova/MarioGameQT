#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {

    ui_factory->create_ship({20, 25}, 15, 2);
    ui_factory->create_mario({22, 22}, 3, 3);

    ui_factory->create_flying_enemy({50, 8}, 3, 2, 50, 80);

    ui_factory->create_box({40, 20}, 5, 3);     
    ui_factory->create_box({45, 20}, 5, 3);
    ui_factory->create_box({50, 20}, 5, 3);
    ui_factory->create_full_box({40, 13}, 5, 3);

    ui_factory->create_jumping_enemy({70, 12}, 3, 2);

    ui_factory->create_ship({70, 15}, 15, 12);
    ui_factory->create_box({70, 5}, 15, 3);
    // ui_factory->create_enemy({72, 12}, 3, 2);
    // ui_factory->create_enemy({78, 12}, 3, 2);
    
    ui_factory->create_box({95, 20}, 5, 3);
    ui_factory->create_box({100, 20}, 5, 3);      
    ui_factory->create_box({105, 20}, 5, 3);
    ui_factory->create_full_box({95, 13}, 5, 3);

    ui_factory->create_ship({130, 25}, 15, 2);
    ui_factory->create_enemy({133, 23}, 3, 2);

    ui_factory->create_ship({160, 25}, 20, 2);
}