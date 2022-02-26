#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double width,
    double height,
    point_t pos):
  width(width),
  height(height),
  pos(pos)
{
  std::cout << "Declarated rectangle\n";
}

double Rectangle::getArea() const
{
  return (width * height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width, height, pos};
}

void Rectangle::move(point_t pos)
{
  this->pos = pos;
}

void Rectangle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
