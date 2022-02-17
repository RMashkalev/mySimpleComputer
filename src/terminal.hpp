#pragma once

#include <iostream>

enum colors {
	black = 0,
	red = 1,
	green = 2,
	yellow = 3,
	blue = 4,
	purple = 5,
	cyan = 6,
	white = 7
};

using namespace std;

int mt_clrscr();

int mt_gotoXY (int x, int y);

int mt_getscreensize (int * rows, int * cols);

int mt_setfgcolor (enum colors color);

int mt_setbgcolor (enum colors color);