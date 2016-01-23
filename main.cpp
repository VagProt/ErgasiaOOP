#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "car.h"
#include "entry.h"
#include "segments.h"
#include "highway.h"
#include "myFunctions.h"

using namespace std;


int N, Nsegs, K, Percent;
ofstream logfile;
ofstream outputfile;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    logfile.open("log.txt");
    outputfile.open("output.txt");

    if(argc == 5)
    {
        N = string_to_int(argv[1]);
        Nsegs = string_to_int(argv[2]);
        K = string_to_int(argv[3]);
        Percent = string_to_int(argv[4]);
    }
    else
        cout << "4 arguments required!" << endl;


    highway attiki_odos(Nsegs + 1, K);


    outputfile << "There are " << attiki_odos.get_no_of_vehicles() << " cars in the highway" << endl;

    int sim_counter = 1;
    while(N--)
    {
        outputfile << "On simulation " << sim_counter << " :" << endl;
        attiki_odos.operate();
        sim_counter++;
    }


    //outputfile.close();
    //logfile.close();

    cout << "Operation of highway finished successfully" <<endl;
    cout << "See output.txt and log.txt for further information" << endl;

    return 0;
}
