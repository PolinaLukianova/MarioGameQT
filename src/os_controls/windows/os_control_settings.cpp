#include "os_control_settings.hpp"
#include <QApplication>
#include <windows.h>

void biv::os::init_settings() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void biv::os::init_settings(int argc, char* argv[]) {
	static QApplication* app = new QApplication(argc, argv);
	init_settings();
}

void biv::os::set_cursor_start_position() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
