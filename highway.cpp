#include <cstdlib>
#include "highway.h"
#include "segments.h"

using namespace std;


highway::highway(int no_segs)
{
    cout << "A highway has been created" << endl;

    int rand_cap;
    segment* seg;

    for(int i=0; i<=no_segs; i++)
    {
        rand_cap = rand() % (max_capacity - min_capacity + 1) + min_capacity;
        seg = new segment(rand_cap, i, NULL, NULL);

        Segs.push_back(seg);
    }
    
    if(no_segs+1 >= 2)
    {
        Segs[0]->set_next(Segs[1]);
        Segs[no_segs]->set_prev(Segs[no_segs-1]);
    }
    
    for(int i=1; i<no_segs; ++i)
    {
        Segs[i]->set_next(Segs[i+1]);
        Segs[i]->set_prev(Segs[i-1]);
    }
}


void highway::operate() const
{
    cout << "There are in the highway " << no_cars << " cars.\n";
}
