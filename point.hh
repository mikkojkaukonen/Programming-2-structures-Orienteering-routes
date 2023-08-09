/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: point.hh                                                            #
#                                                                           #
# Description: Saves the information of points.                             #
#                                                                           #
# Writer:                                                                   #
# * Name: Mikko Kaukonen                                                    #                                       #
#############################################################################
*/

#ifndef POINT_HH
#define POINT_HH

#include "orienteeringmap.hh"
#include <string>
#include <map>
#include <vector>

using namespace std;

class point
{
public:

    // Constructor with point data as parameters.
    point(string name, int x, int y, int height, char marker);

    ~point();

    // Returns the point name
    string name() const;
    // Returns the point x coordinate
    int x() const;
    // Returns the point y coordinate
    int y() const;
    // Returns the point height
    int height() const;
    // Returns the point id.
    char marker() const;



private:

    // Stores the information of a point.
    string name_;
    int point_x_;
    int point_y_;
    int height_;
    char marker_;
};

#endif // POINT_HH
