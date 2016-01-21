#include <string>
#include <cstdlib>
#include "segments.h"
#include "entry.h"
#include "car.h"
#include "highway.h"

using namespace std;


segment::segment(int cap, int index, segment* next, segment* prev) : car_cap(cap), seg_index(index), next(next), prev(prev)
{
    cout << "Segment " << index << " has been created" << endl;

    int rand_toll = rand() % max_tolls + 1;
    point_of_entry = new entry("Entrance " + index, index, this, rand_toll);

    for(int i=1; i<=cap; i++)
    {
        car *temp = new car();
        temp->set_seg_id(index);
        temp->set_exit_id(rand() % (Nsegs - index) + index);
        temp->set_if_ready(false);

        cars_in_seg.push_back(temp);
    }
}

segment::~segment()
{
    cout << "Segment " << seg_index << " has been destroyed" << endl;
}

void segment::set_next(segment *nxt)
{
    next = nxt;
}

void segment::set_prev(segment *prv)
{
    prev = prv;
}

int segment::get_no_of_vehicles() const
{
    return cars_in_seg.size();
}

int segment::get_capacity() const
{
    return car_cap;
}

void segment::push_front_car(car *Car)
{
    cars_in_seg.push_front(Car);
}
