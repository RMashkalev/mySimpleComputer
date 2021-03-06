#include "terminal.h"

int mt_clrscr()
{
    printf("\E[H\E[2J");
    return 0;
}

int mt_gotoXY (int x, int y)
{
    printf("\E[%d;%dH", x, y);
    return 0;
}

int mt_getscreensize (int * rows, int * cols)
{
    struct winsize ws;

	if (ioctl(1, TIOCGWINSZ, &ws)) {
		return 1;
	} else {
		*rows = ws.ws_row;
		*cols = ws.ws_col;
	}

	return 0;
}

int mt_setfgcolor (enum colors color)
{
    printf("\E[3%dm", color);
    return 0;
}

int mt_setbgcolor (enum colors color)
{
    printf("\E[4%dm", color);
    return 0;
}