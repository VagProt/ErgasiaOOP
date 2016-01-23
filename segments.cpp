#include <string>
#include <cstdlib>
#include "segments.h"
#include "entry.h"
#include "car.h"
#include "highway.h"
#include "myFunctions.h"

using namespace std;

segment::segment(int cap, int index, segment* next, segment* prev) : car_cap(cap), seg_index(index), next(next), prev(prev)
{
    cout << "Segment " << index << " has been created" << endl;

    int rand_toll = rand() % max_tolls + 1;
    string temp_name = "Entrance " + int_to_string(index);
    point_of_entry = new entry(temp_name, index, this, rand_toll);

    cout << "Adding cars to segment" << endl;

    int rand_cap = rand() % cap + 1;
    for(int i=0; i<rand_cap; i++)
    {
        car *temp = new car();
        temp->set_seg_id(index);
        temp->set_exit_id(rand() % ((Nsegs+1) - index) + index);

        cars_in_seg.push_back(temp);
    }

    cout << "Done adding cars to segment" << endl;
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

void segment::enter()
{
    if(prev != NULL)
    {
        prev->pass();
        point_of_entry->operate();
    }
}

void segment::exit()
{
    for(list<car*>::iterator iter = cars_in_seg.begin(); iter != cars_in_seg.end();)
    {
        if((*iter)->get_if_ready()  &&  (*iter)->get_exit_id() == seg_index)
        {
            cout << "A car in segment " << seg_index << " is about to exit the highway" << endl;

            delete (*iter);
            cars_in_seg.erase(iter++);
        }
        
        else
            ++iter;
    }
}

void segment::pass()
{
    for(list<car*>::iterator iter = cars_in_seg.begin(); iter != cars_in_seg.end();)
    {
        if(next->get_no_of_vehicles() == next->car_cap)
            break;
            
        if((*iter)->get_if_ready()  &&  ((*iter)->get_exit_id() > seg_index))
        {
            cout << "A car is exiting segment " << seg_index << " and entering segment " << next->seg_index << endl;

            car* temp_car = *iter;
            cars_in_seg.erase(iter++);
            temp_car->set_if_ready(false);
            temp_car->set_seg_id(seg_index + 1);
            next->cars_in_seg.push_front(temp_car);
        }

        else
            ++iter;
    }
}

void segment::set_ready()
{
    int len = cars_in_seg.size();
    int rand_index, perc = len * (Percent / 100);
    vector <bool> used_indexes(len, false);

    for(int i=1; i<=perc; i++)
    {
        do
        {
            rand_index = rand() % len;
        }while(used_indexes[rand_index]);

        used_indexes[rand_index] = true;

        for(list<car*>::iterator iter = cars_in_seg.begin(); iter != cars_in_seg.end(); iter++, rand_index--)
            if(rand_index == 0)
            {
                 (*iter)->set_if_ready(true);
                 break;
            }
    }

}

void segment::operate()
{
    cout << "Segment " << seg_index << " is operating" << endl;
    exit();
    enter();
    set_ready();
}
