#include "memory.h"

static int *sc_ram = NULL;
int err_flags = 0;

int sc_memoryInit()
{
    if(sc_ram != NULL)
        free(sc_ram);
    
    sc_ram = malloc(100 * sizeof(sc_ram));

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
        printf("Invalid cell address\n");
        err_flags = err_flags | M;
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
        printf("Invalid cell address\n");
        err_flags = err_flags | M;
        return 1;
    }
}

int sc_memorySave (FILE * filename)
{
    if(fwrite(sc_ram, sizeof(int), 100, filename) != 100)
    {
        printf("Failed to save\n");
        return -1;
    }    
    else
    {
        printf("Save successfully\n");
        fseek(filename, 0, SEEK_SET);
        return 0;
    }
        
}

int sc_memoryLoad (FILE * filename)
{
    if(fread(sc_ram, sizeof(int), 100, filename) != 100)
    {
        printf("Failed to load\n");
        return -1;
    }    
    else
    {
        printf("Upload Successful\n");
        fseek(filename, 0, SEEK_SET);
        return 0;
    }
        
}

int sc_regInit ()
{
    err_flags = 0;
    return 0;
}

int sc_regSet (int reg, int value) 
{
    if(reg == P || reg == O || reg == M || reg == T || reg == E || reg == H)
    {
        if(value == 1)
        {
            err_flags = err_flags | reg;
            return 0;
        }
        else    
        {
            err_flags = err_flags & ~reg;
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
		*value = err_flags & P;

	else if (reg == O)
		*value = err_flags & O;

	else if (reg == M)
		*value = err_flags & M;

	else if (reg == T)
		*value = err_flags & T;

	else if (reg == E)
		*value = err_flags & E;

    else if (reg == H)
		*value = err_flags & H;
        
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

	if ((*command > 0 && *command < 10) ||
		(*command > 11 && *command < 20) ||
		(*command > 21 && *command < 30) ||
		(*command > 33 && *command < 40) ||
		(*command > 44 && *command < 51) ||
		*command > 79) {
		sc_regSet(E, 1);
		return 1;
	}

    *command = value >> 7;
	*operand = value & 0x7F;

	return 0;
}

void print_arr()
{
    for (int i = 0; i < 100; i++)
        printf("%d ", sc_ram[i]);
    printf("\n");
}