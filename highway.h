#ifndef _highway_h
#define _highway_h

#include <iostream>
#include <vector>

using namespace std;

extern int N, Nsegs, K, Percent;

class segment;

static const int min_capacity = 10;
static const int max_capacity = 20;

class highway
{
    public:
        highway(int);
        ~highway();
        void operate() const;

    private:
        vector <segment*> Segs;
        int no_cars;

};

#endif // _highway_h
