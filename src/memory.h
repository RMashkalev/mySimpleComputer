#pragma once

#include <stdio.h>
#include <stdlib.h>

#define P 0x01 // Переполнение
#define O 0x02 // Деление на 0
#define M 0x04 // Выход за границы
#define T 0x08 // Игнорирование тактовых импульсов
#define E 0x10 // Неверная команда
#define H 0x20 // Другое

int sc_memoryInit ();

int sc_memorySet (int address, int value);

int sc_memoryGet (int address, int * value);

int sc_memorySave (FILE * filename);

int sc_memoryLoad (FILE * filename);

int sc_regInit ();

int sc_regSet (int reg, int value);

int sc_regGet (int reg, int *value);

    

void print_arr();