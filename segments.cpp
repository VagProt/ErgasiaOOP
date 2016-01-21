#include <string>
#include <sstream>
#include <cstdlib>
#include "segments.h"
#include "entry.h"
#include "car.h"
#include "highway.h"

using namespace std;

string operator+(string const &a, int b)
{
  ostringstream oss;
  oss << a << b;
  return oss.str();
}

segment::segment(int cap, int index, segment* next, segment* prev):car_cap(cap), seg_index(index), next(next), prev(prev)
{
    cout << "Segment " << index << " has been created" << endl;

    int rand_int = rand()%max_tolls + 1;
    point_of_entry = new entry("Entrance " + index, index, this, rand_int);

    rand_int = rand()%cap + 1;
    car* temp;

    for(int i=0; i<cap; i++)
    {
        temp = new car();
        temp->set_seg_id(index);
        temp->set_exit_id(rand()%(Nsegs-index)+index);

        cars_in_seg.push_back(temp);
    }
}

segment::~segment()
{
    cout << "Segment " << seg_index << " has been destroyed" << endl;
}
