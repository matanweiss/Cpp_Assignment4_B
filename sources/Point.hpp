#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <float.h>

using namespace std;

class Point
{
    double xAxis;
    double yAxis;

public:
    Point(double xAxis, double yAxis);
    double distance(const Point& other);
    string print();
    static Point moveTowards(Point src, Point dest, double distance);
};
