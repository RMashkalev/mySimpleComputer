#include "memory.h"
#include "terminal.h"
#include "BigChar.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int value = 0, a, rows, cols, bc;
    char string[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\n'};
    
    
    FILE *ram = fopen("ram.dat", "w+b");
    if (ram == NULL)
    {
        printf("Ошибка открытия файла");
        return 1;
    }

    if((bc = open("bc.txt", O_WRONLY)) == -1)
    {
        printf("Chlen\n");
        return -1;
    }

    mt_clrscr();
    bc_printA (string);
    printf("\n");
    bc_box(1, 2, 10, 11);
    bc_printbigchar(bc8, 12, 2, black, white);
    printf("\n\n");


    // mt_clrscr();

    // mt_gotoXY (5, 10);
    // mt_setfgcolor(yellow);
    // printf("Машкалев Роман");

    // mt_gotoXY (6, 8);
    // mt_setfgcolor(green);
    // mt_setbgcolor (white);
    // printf("ИВ-022");
    // mt_setbgcolor (black);


    // mt_gotoXY (10, 1);
    // mt_setfgcolor(white);
    // mt_setbgcolor (black);

    // mt_getscreensize (&rows, &cols);

    // printf("%d %d\n", rows, cols);

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