#ifndef _entry_h
#define _entry_h

#include <iostream>
#include <string>

using namespace std;

class List;
class car;
class segment;

class toll
{
    protected:
        List* cars_in_queue;

    public:
        void add_to_queue(car*);
        void add_to_seg();

};

class e_toll: public toll
{

    public:

};

class h_toll: public toll
{

    public:

};

class entry
{
    string name;
    e_toll* e_toll_array;
    h_toll* h_toll_array;

    segment* home;

    public:

};

#endif // _entry_h
