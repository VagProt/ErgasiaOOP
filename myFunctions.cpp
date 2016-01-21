#include "myFunctions.h"
#include <sstream>
#include <string>

using namespace std;


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


string operator+(const string &a, int b)
{
    ostringstream oss;
    oss << a << b;
    return oss.str();
}
