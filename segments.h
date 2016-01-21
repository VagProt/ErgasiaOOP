#ifndef _segments_h
#define _segments_h

#include <iostream>
#include <list>

using namespace std;

class entry;
class car;

static const int max_tolls = 10;

class segment
{
    public:
        segment(int, int, segment*, segment*);
        ~segment();
        void set_next(segment*);
        void set_prev(segment*);
        void enter();
        void exit();
        void pass();
        int get_no_of_vehicles() const;

    private:
        entry* point_of_entry;

        list <car*> cars_in_seg;
        int car_cap;
        int seg_index;

        segment* next;
        segment* prev;
};

#endif // _segments_h
