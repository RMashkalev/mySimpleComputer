#include "memory.h"
#include "terminal.h"

int main()
{
    int value = 0, a;
    
    FILE *ram = fopen("ram.dat", "w+b");
    if (ram == NULL)
    {
        printf("Ошибка открытия файла");
        return 1;
    }

    mt_clrscr();

    mt_gotoXY (5, 10);
    mt_setfgcolor(red);
    printf("Машкалев Роман");

    mt_gotoXY (6, 8);
    mt_setfgcolor(green);
    mt_setbgcolor (white);
    printf("ИВ-022");

    mt_gotoXY (10, 1);
    mt_setfgcolor(white);
    mt_setbgcolor (black);

    // sc_memoryInit ();

    // sc_memorySet (0, 100);

    // sc_memorySet(4, 56);

    // sc_memorySet(9, 12);

    // print_arr();

    // sc_memorySave (ram);

    // sc_memoryInit ();

    // sc_memoryLoad (ram);

    // print_arr();

    return 0;
}