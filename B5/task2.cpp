#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "functions.hpp"
#include "shape.hpp"

int lutsaj::task2(std::istream& in, std::ostream& out)
{
  std::vector< lutsaj::Shape > shapes;
  std::istream_iterator< lutsaj::Shape > beginIter(in);
  std::istream_iterator< lutsaj::Shape > endIter;
  std::copy(beginIter, endIter, std::back_inserter(shapes));
  if (in.fail() && !in.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }

  int verticesCounter = std::accumulate(shapes.begin(), shapes.end(), 0, lutsaj::verticesSummator);

  int squaresCounter = std::count_if(shapes.begin(), shapes.end(), lutsaj::isSquare);
  int rectanglesCounter = std::count_if(shapes.begin(), shapes.end(), lutsaj::isRectangle);
  int trianglesCounter = std::count_if(shapes.begin(), shapes.end(), lutsaj::isTriangle);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), lutsaj::isPentagon), shapes.end());

  std::vector< lutsaj::Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), lutsaj::returnFrontPoint);

  std::sort(shapes.begin(), shapes.end());

  out << "Vertices: " << verticesCounter << "\n";
  out << "Triangles: " << trianglesCounter << "\n";
  out << "Squares: " << squaresCounter << "\n";
  out << "Rectangles: " << rectanglesCounter << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< lutsaj::Point >(out, " "));
  out << "\n";
  out << "Shapes:" << "\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< lutsaj::Shape >(out, "\n"));
  return 0;
}
