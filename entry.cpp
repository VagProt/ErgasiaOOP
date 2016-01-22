#include <cstdlib>
#include "entry.h"
#include "car.h"
#include "highway.h"
#include "segments.h"

using namespace std;


int h_toll::h_max = 0;
int e_toll::e_max = 0;


entry::entry(string n, int index, segment* p, int no_tolls) : name(n), seg_index(index), home(p)
{
    cout << "Entry with name " << n << " has been created" << endl;

    toll* temp;

    for(int i=1; i<=(int)(no_tolls*0.6 + 0.5); i++)
    {
        temp = new h_toll(index);
        h_toll_vector.push_back(temp);
    }

    for(int i=1; i<=(int)(no_tolls*0.4 + 0.5); i++)
    {
        temp = new e_toll(index);
        e_toll_vector.push_back(temp);
    }
}

toll::toll(int curr_seg)
{
    cout << "A toll has been created" << endl;

    add_rand_cars(curr_seg);
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
    cout << "Adding cars to toll" << endl;

    int no_of_cars = rand()%max_cars + 1;

    for(int i=0; i<no_of_cars; i++)
    {
        car *temp = new car();
        temp->set_seg_id(-1);
        temp->set_exit_id(rand() % ((Nsegs+1) - curr_seg) + curr_seg);

        cars_in_queue.push(temp);
    }
}

car* toll::get_car() const
{
    return cars_in_queue.front();
}

void toll::pop_car()
{
    cars_in_queue.pop();
}

int toll::get_size() const
{
    return cars_in_queue.size();
}

void entry::operate()
{
    int pos = 0, h_entry_cnt = 0, e_entry_cnt = 0;
    bool h_flag = false, e_flag = false;

    while(home->get_no_of_vehicles() < home->get_capacity())
    {
        if(h_entry_cnt < h_toll::h_max)
        {
            for(int i=0; i<h_toll_vector.size(); ++i)
            {
                if(h_toll_vector[i]->get_size())
                {
                    car* Car = h_toll_vector[i]->get_car();
                    h_toll_vector[i]->pop_car();
                    Car->set_seg_id(seg_index);
                    home->push_front_car(Car);

                    ++h_entry_cnt;
                    h_flag = true;
                }

                if(home->get_no_of_vehicles() == home->get_capacity()  ||  h_entry_cnt == h_toll::h_max)
                    break;
            }
        }

        if(e_entry_cnt < e_toll::e_max)
        {
            for(int i=0; i<e_toll_vector.size(); ++i)
            {
                if(e_toll_vector[i]->get_size())
                {
                    car* Car = e_toll_vector[i]->get_car();
                    e_toll_vector[i]->pop_car();
                    Car->set_seg_id(seg_index);
                    home->push_front_car(Car);

                    ++e_entry_cnt;
                    e_flag = true;
                }

                if(home->get_no_of_vehicles() == home->get_capacity()  ||  e_entry_cnt == e_toll::e_max)
                    break;
            }
        }

        if((h_entry_cnt == h_toll::h_max  &&  e_entry_cnt == e_toll::e_max)  ||  (!h_flag  &&  !e_flag))
            break;
    }

    if(h_entry_cnt == h_toll::h_max)
        ++h_toll::h_max;
    else
        --h_toll::h_max;

    if(e_entry_cnt == e_toll::e_max)
        ++e_toll::e_max;
    else
        --e_toll::e_max;

    for(int i=0; i<h_toll_vector.size(); i++)
        h_toll_vector[i]->add_rand_cars(seg_index);

    for(int i=0; i<e_toll_vector.size(); i++)
        e_toll_vector[i]->add_rand_cars(seg_index);
}
