#include "Point.hpp"
#include <string>

Point::Point(double xAxis, double yAxis) : xAxis(xAxis), yAxis(yAxis) {}
double Point::distance(const Point &other) {
  return sqrt(pow(xAxis - other.xAxis, 2) + pow(yAxis - other.yAxis, 2));
}
string Point::print() {
  return "(" + to_string(xAxis) + "," + to_string(yAxis) + ")";
}
Point Point::moveTowards(Point src, Point dest, double distance) {
  if (distance == 0)
    return src;
  if (src.distance(dest) <= distance)
    return dest;
   if (distance < 0)
            throw invalid_argument("distance should be positive");
  double dx = dest.xAxis - src.xAxis;
  double dy = dest.yAxis - src.yAxis;
  double scale = distance / src.distance(dest);
  return Point(src.xAxis + scale * dx, src.yAxis + scale * dy);
}
