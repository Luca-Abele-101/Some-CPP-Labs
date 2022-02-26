#include "circle.hpp"
#include <iostream>

constexpr double C_PI = 3.14;

lutsaj::Circle::Circle(double radius, point_t pos):
  radius(radius),
  pos(pos)
{
  if (radius < 0)
  {
    throw(std::invalid_argument("Negative radius"));
  }
}

double lutsaj::Circle::getArea() const
{
  return (C_PI * radius * radius);
}

void lutsaj::Circle::move(lutsaj::point_t pos)
{
  this->pos = pos;
}

void lutsaj::Circle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}

lutsaj::rectangle_t lutsaj::Circle::getFrameRect() const
{
  return { (2 * radius), (2 * radius), pos };
}

void lutsaj::Circle::scale(double k)
{
  if (k <= 0)
  {
    throw(std::invalid_argument("Negative coefficient"));
  }
  radius *= k;
}

lutsaj::Shape::ShapePtr lutsaj::Circle::clone() const
{
  return std::make_shared< lutsaj::Circle >(*this);
}
