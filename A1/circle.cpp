#include "circle.hpp"
#include <iostream>

constexpr float C_PI = 3.141592F;

Circle::Circle(double radius, point_t pos):
  radius(radius),
  pos(pos)
{
  if (radius < 0)
  {
    this->radius = 0;
  }
}

double Circle::getArea() const
{
  return (C_PI * radius * radius);
}

rectangle_t Circle::getFrameRect() const
{
  return { (2 * radius), (2 * radius), pos };
}

void Circle::move(point_t pos)
{
  this->pos = pos;
}

void Circle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
