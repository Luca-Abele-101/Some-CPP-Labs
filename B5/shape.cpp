#include "shape.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "functions.hpp"

bool lutsaj::operator<(const Shape& shp1, const Shape& shp2)
{
  if (shp1.size() < 5 && shp2.size() < 5)
  {
    if (shp1.size() == 4 && shp2.size() == 4)
    {
      return isSquare(shp1) && !isSquare(shp2);
    }
  }
  return (shp1.size() < shp2.size());
}

std::istream& lutsaj::operator>>(std::istream& in, lutsaj::Shape& shp)
{
  size_t n = 0;
  in >> n;
  if (!in || in.get() != ' ')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  lutsaj::Shape tempShp;
  tempShp.reserve(n);
  std::copy_n(std::istream_iterator< Point >(in), n, std::back_inserter(tempShp));
  if ((in.fail() && !in.eof()) || tempShp.size() != n)
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  shp.swap(tempShp);
  return in;
}

std::ostream& lutsaj::operator<<(std::ostream& out, const lutsaj::Shape& shp)
{
  out << shp.size() << ' ';
  std::copy(shp.begin(), shp.end(), std::ostream_iterator< lutsaj::Point >(out, " "));
  return out;
}

bool lutsaj::isTriangle(const Shape& shp)
{
  return (shp.size() == 3);
}

bool lutsaj::isSquare(const Shape& shp)
{
  return (isRectangle(shp) && checkSidesEquality(shp));
}

bool lutsaj::isRectangle(const Shape& shp)
{
  return (shp.size() == 4);
}

bool lutsaj::isPentagon(const Shape& shp)
{
  return (shp.size() == 5);
}
