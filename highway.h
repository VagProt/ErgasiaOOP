#ifndef _highway_h
#define _highway_h

#include <iostream>
#include <vector>

using namespace std;


class segment;

//const int min_capacity = 10;
//const int max_capacity = 20;

class highway
{
    public:
        highway(int, int);
        ~highway();

        void operate();
        int get_no_of_vehicles() const;

    private:
        vector <segment*> Segs;
        int no_cars;

};

#endif // _highway_h
