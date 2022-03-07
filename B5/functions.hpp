#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iosfwd>

#include "shape.hpp"
#include "point.hpp"

namespace lutsaj
{
  bool checkSidesEquality(const lutsaj::Shape& shp);
  int getSquaredDistance(const Point& p1, const Point& p2);
  int verticesSummator(int vertices, const lutsaj::Shape& shp);
  lutsaj::Point returnFrontPoint(const lutsaj::Shape& shp);
}
#endif
