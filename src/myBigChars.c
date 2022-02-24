#include "myBigChars.h"

int bc_printA (char * str)
{
    if (!str) {
		return 1;
	}
    
    printf("\E(B%s\E(B", str);

    return 0;
}