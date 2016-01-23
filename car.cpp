#include "car.h"
#include "myFunctions.h"

using namespace std;

car::car():is_ready(false)
{
    logfile << "A car has been created" << endl;
}

car::~car()
{
    logfile << "Car in segment " << seg_id << " with exit segment " << exit_id << " has been destroyed" << endl;
}

void car::set_exit_id(int ext)
{
    exit_id = ext;
}

int car::get_exit_id()
{
    return exit_id;
}

void car::set_seg_id(int seg)
{
    seg_id = seg;
}

int car::get_seg_id()
{
    return seg_id;
}

void car::set_if_ready(bool r)
{
    is_ready = r;
}

bool car::get_if_ready()
{
    return is_ready;
}
