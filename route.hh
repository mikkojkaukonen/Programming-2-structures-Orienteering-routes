/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: route.hh                                                            #
# Description: Module that compiles an individual route by connecting       #
# points and their information one at a time. Also prints the               #
# given route with points and perform calculations of individual routes.    #
#                                                                           #
# Writer:                                                                   #
# * Name: Mikko Kaukonen                                                    #                                       #
#############################################################################
*/


#ifndef ROUTE_HH
#define ROUTE_HH

#include "orienteeringmap.hh"
#include "point.hh"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;


class route
{
public:
    route();
    ~route();

    // Connects two existing points such that the point 'to' will be
    // immediately after the point 'from'.
    void add_route(class point* from_point, class point* to_point);

    // Prints the given route with names of the points.
    void print_one_route();

    // Calculates the length of a route by calculating the distances
    // between points and combines these and prints the length.
    void route_length();

    // Checks if the named point found in the route.
    // Returns the calculated rises from the calculate_rise funktion.
    int greatest_rise(const string &point_name);


private:

    // Vector where the route is created
    vector<class point*> Route_;

    // Calculates recursively the continuous rise from a named point.
    int calculate_rise(unsigned int index);


};

#endif // ROUTE_HH
