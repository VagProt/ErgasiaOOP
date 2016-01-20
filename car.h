#ifndef _car_h
#define _car_h

#include <iostream>

using namespace std;

class car
{
    int exit_id;
    int seg_id;
    bool is_ready;

    public:
        car();
        ~car();

        void set_exit_id(int);
        int get_exit_id();
        void set_seg_id(int);
        int get_seg_id();
        void set_if_ready(bool);
        bool get_if_ready();

};

#endif // _car_h
