#include <iostream>
#include <cstdlib>
#include <ctime>
#include "car.h"
#include "entry.h"
#include "segments.h"
#include "highway.h"
#include "myFunctions.h"

using namespace std;


int N, Nsegs, K, Percent;


int main(int argc, char* argv[])
{
    if(argc == 5)
    {
        N = string_to_int(argv[1]);
        Nsegs = string_to_int(argv[2]);
        K = string_to_int(argv[3]);
        Percent = string_to_int(argv[4]);
    }
    else
        cout << "4 arguments required!" << endl;

    srand(time(NULL));

    highway attiki_odos(Nsegs, K);

    while(N--)
    {

    }

    return 0;
}
