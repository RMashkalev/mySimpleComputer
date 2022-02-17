#include "memory.hpp"
#include "terminal.hpp"

int main()
{
    int value = 0, a;
    
    FILE *ram = fopen("ram.dat", "w+b");
    if (ram == NULL)
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    // sc_memoryInit ();

    // sc_memorySet (0, 100);
    
    // print_arr();
    // // cout << value << endl;

    // sc_memorySave (ram);

    // sc_memoryLoad (ram);

    // //sc_memoryInit ();

    // //print_arr();

    // sc_regInit ();

    // sc_regSet (H, 1);

    // sc_regGet (H, &value);

    // cout << value << endl;

    mt_clrscr();

    mt_gotoXY (5, 10);
    mt_setfgcolor(red);
    cout << "Машкалев Роман";

    mt_gotoXY (6, 8);
    mt_setfgcolor(green);
    mt_setbgcolor (white);
    cout << "ИВ-022";

    mt_gotoXY (10, 1);
    mt_setfgcolor(white);
    mt_setbgcolor (black);


    return 0;
}