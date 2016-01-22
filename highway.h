#ifndef _highway_h
#define _highway_h

#include <iostream>
#include <vector>

using namespace std;


class segment;

static const int min_capacity = 10;
static const int max_capacity = 20;

class highway
{
    public:
        highway(int, int);
        ~highway();
        void operate() const;

    private:
        vector <segment*> Segs;
        int no_cars;

};

#endif // _highway_h
