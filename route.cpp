#include "route.hh"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

route::route()
{

}

route::~route()
{

}


void route::add_route(point* from_point, point* to_point)
{
    // Cheks if the route allready have points.
    if(Route_.size() == 0)
    {
        // If not inserts the firsth added point as a from point.
        Route_.push_back(from_point);
    }

    // Inserts rest of the points as to points
    Route_.push_back(to_point);
}


void route::print_one_route()
{
    unsigned int i = 0;

    {
        // Prints the firsth point of a named route
        cout << " " << Route_.at(i)->name() << endl;

        // Prints the rest of the points of a named route
        while ( i < (Route_.size() -1))
        {
            cout << "  -> " << Route_.at(i+1)->name() << endl;

            ++i;
        }

    }

}

void route::route_length()
{
    unsigned int i = 0;

    float distance = 0;

    while( i < (Route_.size() -1))
    {
        // Specified variables for route calculation.
        int x1 = Route_.at(i)->x();
        int y1 = Route_.at(i)->y();
        int x2 = Route_.at(i+1)->x();
        int y2 = Route_.at(i+1)->y();

        // Calculates the length of the route.
        distance = distance + sqrt(pow((x1 - x2), 2) + pow((y1- y2), 2));

        ++i;
    }

    // Prints the length of the route.
    cout << distance;

}


int route::greatest_rise(const string &point_name)
{
    unsigned int i = 0;

    // Goes throug the routes
    while( i < (Route_.size() -1))
    {

        // And cheks if the named point found on the route.
        if(point_name == Route_.at(i)->name())
        {

            return calculate_rise (i);

        }
        ++i;

    }
    return 0;
}

int route::calculate_rise(unsigned int index)
{
    // Variable for the rise
    int height_rise = 0;

    // Checks if the named point is the last one of the route
    if(index >= Route_.size() -1)
    {
        return 0;
    }

    // Calculates the height difference between the points.
    height_rise = Route_.at(index+1)->height() - Route_.at(index)->height();

    // Checks if the next point is lower than current.
    if(height_rise < 0)
    {       
        return 0;
    }

    // If next point is on same level or higher, returns
    // rise value + calls function recursively for next point.
    return height_rise + calculate_rise(index+1);
}







