#include "functions.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <functional>

#include "point.hpp"
#include "shape.hpp"

bool lutsaj::checkSidesEquality(const lutsaj::Shape& shp)
{
  int last = getSquaredDistance(shp[0], shp[3]);
  std::vector< int > sides;
  sides.reserve(shp.size());
  std::transform(shp.begin() + 1, shp.end(), shp.begin(), std::back_inserter(sides), getSquaredDistance);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), std::placeholders::_1, last));
}

int lutsaj::getSquaredDistance(const Point& p1, const Point& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

int lutsaj::verticesSummator(int vertices, const lutsaj::Shape& shp)
{
  return vertices + shp.size();
}

lutsaj::Point lutsaj::returnFrontPoint(const lutsaj::Shape& shp)
{
  return shp.front();
}
