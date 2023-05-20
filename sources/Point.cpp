#include "Point.hpp"
#include <string>

Point::Point(double xAxis, double yAxis) : xAxis(xAxis), yAxis(yAxis) {}
double Point::getX()const { return xAxis; }
double Point::getY()const { return yAxis; }
double Point::distance(const Point &other) {

  return sqrt(pow(xAxis - other.getX(), 2) + pow(yAxis - other.getY(), 2));
}
string Point::print() {
  return "(" + to_string(xAxis) + "," + to_string(yAxis) + ")";
}
Point Point::moveTowards(Point src, Point dest, double distance) {
  if (distance == 0)
    return src;
  if (src.distance(dest) <= distance)
    return dest;
  double m = (src.getY() - dest.getY()) / (src.getX() - dest.getX());
  double b = src.getY() - m * src.getX();
  double x = src.getX() + distance / (pow(b, 2) + 1);
  double y = m * x + b;
  return Point(x, y);
}
