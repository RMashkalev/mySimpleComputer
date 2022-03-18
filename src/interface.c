#include "interface.h"
#include "BigChar.h"
#include "terminal.h"
#include "memory.h"
#include <stdio.h>

void show_interface()
{
    // bc_setbigcharpos(bcp, 0, 0, 1);
    mt_clrscr();
    print_memory();
    print_keys();
    print_accum();
    print_instrcntr();
    print_operation();
    print_flags();
    print_cell();
    mt_gotoXY(1, 25);
}

void print_memory()
{
    mt_setfgcolor(red);
    bc_box(1, 1, 63, 12);
    mt_gotoXY(28, 1);
    printf(" Memory ");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mt_gotoXY(2 + j * 6, i + 2);
            printf("+%X ", array[i * 10 + j]);
        }
    }
}

void print_cell()
{
    int memvalue = array[instructionCounter];

    bc_box(1, 13, 51, 23);
    for (int i = 4; i > 0; i--) {
        bc_printbigchar(
                bcAll[memvalue % 16], 2 + 10 * i, 14, white, black);
        memvalue /= 16;
    }
    bc_printbigchar(bcp, 2, 14, white, black);
}

void print_keys()
{
    mt_setfgcolor(green);
    bc_box(53, 13, 89, 23);
    mt_gotoXY(57, 14);
    printf(" Keys: ");
    mt_gotoXY(55, 15);
    printf("l   - load");
    mt_gotoXY(55, 16);
    printf("s   - save");
    mt_gotoXY(55, 17);
    printf("r   - run");
    mt_gotoXY(55, 18);
    printf("t   - step");
    mt_gotoXY(55, 19);
    printf("i   - reset");
    mt_gotoXY(55, 20);
    printf("F5  - accumulator");
    mt_gotoXY(55, 21);
    printf("F6  - instructionCounter");
}

void print_accum()
{
    bc_box(65, 1, 89, 3);
    mt_gotoXY(72, 1);
    printf("accumulator");
    mt_gotoXY(75, 2);
    printf("%d", accumulator);
}

void print_instrcntr()
{
    bc_box(65, 4, 89, 6);
    mt_gotoXY(69, 4);
    printf("instructionCounter");
    mt_gotoXY(77, 5);
    printf("%d", instructionCounter);
}

void print_operation()
{
    bc_box(65, 7, 89, 9);
    mt_gotoXY(73, 7);
    printf("operation");
    mt_gotoXY(76, 8);
    printf("???");
}

void print_flags()
{
    bc_box(65, 10, 89, 12);
    mt_gotoXY(75, 10);
    printf("flags");
    mt_gotoXY(73, 11);
    printf("A B C D E");
}
