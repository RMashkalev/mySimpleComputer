#include "memory.hpp"

static int *sc_ram = NULL;
int err_flag = 0;

int sc_memoryInit()
{
    if(sc_ram != NULL)
        delete sc_ram;
    
    sc_ram = new int[100];

    return 0;
}

int sc_memorySet(int address, int value)
{
    if(address >= 0 && address < 100)
    {
        sc_ram[address] = value;
        return 0;
    }
    else
    {
        cout << "Неверный адрес ячейки" << endl;
        err_flag = err_flag | M;
        return 1;
    }
}

int sc_memoryGet (int address, int * value)
{
    if(address >= 0 && address < 100)
    {
        *value = sc_ram[address];
        return 0;
    }
    else
    {
        cout << "Неверный адрес ячейки" << endl;
        err_flag = err_flag | M;
        return 1;
    }
}

int sc_memorySave (FILE * filename)
{
    if(fwrite(sc_ram, sizeof(int), 100, filename) != 100)
    {
        cout << "Не удалось записать ram в память" << endl;
        return -1;
    }    
    else
    {
        cout << "Запись успешна" << endl;
        fseek(filename, 0, SEEK_SET);
        return 0;
    }
        
}

int sc_memoryLoad (FILE * filename)
{
    if(fread(sc_ram, sizeof(int), 100, filename) != 100)
    {
        cout << "Не удалось загрузить ram из памяти" << endl;
        return -1;
    }    
    else
    {
        cout << "Загрузка успешна" << endl;
        fseek(filename, 0, SEEK_SET);
        return 0;
    }
        
}

int sc_regInit ()
{
    err_flag = 0;
    return 0;
}

int sc_regSet (int reg, int value) 
{
    if(reg == P || reg == O || reg == M || reg == T || reg == E || reg == H)
    {
        if(value == 1)
        {
            err_flag = err_flag | reg;
            return 0;
        }
        else    
        {
            err_flag = err_flag & ~reg;
            return 0;
        }
    }
    return 1;
}

int sc_regGet (int reg, int *value)
{
    if (!value) {
		return 1;
	}

	if (reg == P)
		*value = err_flag & P;

	else if (reg == O)
		*value = err_flag & O;

	else if (reg == M)
		*value = err_flag & M;

	else if (reg == T)
		*value = err_flag & T;

	else if (reg == E)
		*value = err_flag & E;

    else if (reg == H)
		*value = err_flag & H;
        
	else
		return 1;

	return 0;
}

int sc_commandEncode (int command, int operand, int * value) 
{
    if ((command > 0 && command < 10) ||
		(command > 11 && command < 20) ||
		(command > 21 && command < 30) ||
		(command > 33 && command < 40) ||
		(command > 44 && command < 51) ||
		command > 79) {
		sc_regSet(E, 1);
		return 1;
	}

	if (operand < 0 || operand > 127) {
		return 1;
	}

	*value = *value | (command << 7);
	*value = *value | operand;

	return 0;
}

int sc_commandDecode (int value, int * command, int * operand)
{
    if ((value >> 14) != 0) {
		sc_regSet(H, 1);
		return 1;
	}

	*command = value >> 7;
	if ((*command > 0 && *command < 10) ||
		(*command > 11 && *command < 20) ||
		(*command > 21 && *command < 30) ||
		(*command > 33 && *command < 40) ||
		(*command > 44 && *command < 51) ||
		*command > 79) {
		sc_regSet(E, 1);
		return 1;
	}

	*operand = value & 0b1111111;

	return 0;
}

void print_arr()
{
    for(int i = 0; i < 100; i++)
        cout << sc_ram[i] << " ";
    cout << endl;
}