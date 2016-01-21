#include <iostream>
#include <cstdlib>
#include "car.h"
#include "entry.h"
#include "segments.h"
#include "highway.h"

using namespace std;

int N, Nsegs, K, Percent;

int main(int argc, char* argv[])
{
    if(argc == 5)
    {
        N = atoi(argv[1]);
        Nsegs = atoi(argv[2]);
        K = atoi(argv[3]);
        Percent = atoi(argv[4]);
    }
    else
        cout << "5 arguments required!" << endl;



    return 0;
}
