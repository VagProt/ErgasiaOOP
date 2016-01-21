#include "myFunctions.h"


int string_to_int(char *str) 
{
    int ret = 0;

    while(*str != '\0')
    {
        ret = ret*10 + (*str - '0');
        ++str;
    }

    return ret;
}
