#ifndef _myFunctions_h
#define _myFunctions_h

#include <string>
#include <fstream>

using namespace std;

int string_to_int(char *);
string int_to_string(int a);

extern ofstream logfile;
extern ofstream outputfile;

#endif // _myFunctions_h
