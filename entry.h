#ifndef _entry_h
#define _entry_h

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class car;
class segment;
class toll;

const int max_cars = 5;

class entry
{
    public:
        entry(string, int, segment*, int);
        ~entry();

        void operate();

    private:
        string name;
        vector <toll*> h_toll_vector;
        vector <toll*> e_toll_vector;

        int seg_index;
        segment* home;
};

class toll
{
    //friend class entry;

    public:
        toll(int);
        ~toll();
        void add_rand_cars(int);
        car* get_car() const;
        void pop_car();
        int get_size() const;

    protected:
        queue <car*> cars_in_queue;
};

class e_toll: public toll
{
    public:
        static int e_max;

        e_toll(int);
        ~e_toll();

    private:

};

class h_toll: public toll
{
    public:
        static int h_max;

        h_toll(int);
        ~h_toll();

    private:

};

#endif // _entry_h
