#include <cstdlib>
#include "highway.h"
#include "segments.h"

using namespace std;

highway::highway(int no_segs)
{
    cout << "A highway has been created" << endl;

    int rand_int;
    segment* temp;

    for(int i=0; i<no_segs; i++)
    {
        rand_int = rand()%(max_capacity-min_capacity) + min_capacity;
        temp = new segment(rand_int, i, NULL, NULL);

        Segs.push_back(temp);
    }
}
