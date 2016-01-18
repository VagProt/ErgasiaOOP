#ifndef _segments_h
#define _segments_h

#include <iostream>

using namespace std;

class entry;
class List;

class segment
{
    entry* point_of_entry;

    List* cars_in_seg;
    int car_cap;

    segment* next;
    segment* prev;

    public:

};

#endif // _segments_h
