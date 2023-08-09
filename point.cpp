#include "point.hh"

point::point(string name, int x, int y, int height, char marker)
{
    name_ = name;
    point_x_ = x;
    point_y_ = y;
    height_ = height;
    marker_ = marker;
}

point::~point()
{

}

string point::name() const
{
    return name_;
}

int point::x() const
{
    return point_x_;
}

int point::y() const
{
    return point_y_;
}

int point::height() const
{
    return height_;
}

char point::marker() const
{
    return marker_;
}

