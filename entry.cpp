#include <cstdlib>
#include "entry.h"
#include "car.h"
#include "highway.h"

using namespace std;

toll::toll(int curr_seg)
{
    add_rand_cars(curr_seg);

    cout << "A toll has been created" << endl;
}

toll::~toll()
{
    cout << "A toll has been destroyed" << endl;
}

h_toll::h_toll(int curr_seg): toll(curr_seg)
{
    cout << "An h-toll has been created" << endl;
}

h_toll::~h_toll()
{
    cout << "An h-toll has been destroyed" << endl;
}

e_toll::e_toll(int curr_seg): toll(curr_seg)
{
    cout << "An e-toll has been created" << endl;
}

e_toll::~e_toll()
{
    cout << "An e-toll has been destroyed" << endl;
}

void toll::add_rand_cars(int curr_seg)
{
    int no_of_cars = rand()%5 + 1;

    car* temp;

    for(int i=0; i<no_of_cars; i++)
    {
        temp = new car();
        temp->set_seg_id(-1);
        temp->set_exit_id(rand()%(Nsegs-curr_seg)+curr_seg);

        cars_in_queue.push(temp);
    }
}

void entry::operate()
{

}

entry::entry(string n, int i, segment* p, int no_tolls):name(n), seg_index(i), home(p)
{
    cout << "Entry with name " << n << " has been created" << endl;

    toll* temp;

    for(int i=0; i<int(no_tolls*0.6 + 0.5f); i++)
    {
        temp = new h_toll(i);
        h_toll_vector.push_back(temp);
    }

    for(int i=0; i<int(no_tolls*0.4 + 0.5f); i++)
    {
        temp = new e_toll(i);
        e_toll_vector.push_back(temp);
    }
}
