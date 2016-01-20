#ifndef _segments_h
#define _segments_h

#include <iostream>
#include <list>

using namespace std;

class entry;
class car;

class segment
{
    entry* point_of_entry;

    list <car*> cars_in_seg;
    int car_cap;
    int seg_index;

    segment* next;
    segment* prev;

    public:

};

#endif // _segments_h
