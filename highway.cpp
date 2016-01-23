#include <cstdlib>
#include "highway.h"
#include "segments.h"
#include "entry.h"
#include "myFunctions.h"

using namespace std;


highway::highway(int no_segs, int K): no_cars(0)
{
    logfile << "A highway has been created" << endl;

    int cap;
    segment* seg;

    for(int i=0; i<no_segs; i++)
    {
        cout << "Capacity of cars for segment " << i << " : ";
        cin >> cap;
        cout << endl;

        seg = new segment(cap, i, NULL, NULL, no_cars);

        Segs.push_back(seg);
    }

    if(no_segs >= 2)
    {
        Segs[0]->set_next(Segs[1]);
        Segs[no_segs-1]->set_prev(Segs[no_segs-2]);
    }

    for(int i=1; i<no_segs-1; i++)
    {
        Segs[i]->set_next(Segs[i+1]);
        Segs[i]->set_prev(Segs[i-1]);
    }

    h_toll::h_max = K;
    e_toll::e_max = 2*K;
}

highway::~highway()
{
    for(int i=0; i<Segs.size(); i++)
    {
        delete Segs[i];
    }

    logfile << "A highway has been destroyed" << endl;
}

void highway::operate()
{
    outputfile << "Highway is operating" << endl;
    no_cars = 0;

    for(int i=Nsegs; i>=0; --i)
    {
        Segs[i]->operate();
        no_cars += Segs[i]->get_no_of_vehicles();
    }

    outputfile << "There are " << no_cars << " cars in the highway" << endl;
}

int highway::get_no_of_vehicles() const
{
    return no_cars;
}
