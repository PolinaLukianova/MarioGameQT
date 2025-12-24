#pragma once

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <QSet>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"
#include "user_input.hpp"

namespace biv {
	class QtGameMap : public QWidget, public GameMap {
		Q_OBJECT
		
		private:
			std::vector<QtUIObject*> objs;
			static constexpr int CELL_SIZE = 20;
			QSet<int> pressed_keys;
			
		public:
			QtGameMap(const int height, const int width, QWidget* parent = nullptr);
			~QtGameMap();

			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;
			
			biv::os::UserInput get_input();
			
		protected:
			void paintEvent(QPaintEvent* event) override;
			void keyPressEvent(QKeyEvent* event) override;
			void keyReleaseEvent(QKeyEvent* event) override;
	};
}