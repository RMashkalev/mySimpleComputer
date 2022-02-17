#include "terminal.hpp"

int mt_clrscr()
{
    cout << "\E[H\E[2J";
    return 0;
}

int mt_gotoXY (int x, int y)
{
    cout << "\E[" << x << ";" << y << "H";
    return 0;
}

int mt_getscreensize (int * rows, int * cols)
{

	return 0;
}

int mt_setfgcolor (enum colors color)
{
    cout << "\E[3" << color << "m";
    return 0;
}

int mt_setbgcolor (enum colors color)
{
    cout << "\E[4" << color << "m";
    return 0;
}