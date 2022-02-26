#include "rectangle.hpp"
#include <iostream>

lutsaj::Rectangle::Rectangle(double width,
  double height,
  point_t pos):
  width(width),
  height(height),
  pos(pos)
{
  if (width < 0)
  {
    throw(std::invalid_argument("Negative width"));
  }
  if (height < 0)
  {
    throw(std::invalid_argument("Negative height"));
  }
  std::cout << "Declarated rectangle\n";
}

double lutsaj::Rectangle::getArea() const
{
  return (width * height);
}

lutsaj::rectangle_t lutsaj::Rectangle::getFrameRect() const
{
  return { width, height, pos };
}

void lutsaj::Rectangle::move(lutsaj::point_t pos)
{
  this->pos = pos;
}

void lutsaj::Rectangle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}

double lutsaj::Rectangle::getHeight() const
{
  return height;
}

double lutsaj::Rectangle::getWidth() const
{
  return width;
}

void lutsaj::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw(std::invalid_argument("Negative coefficient"));
  }
  width *= k;
  height *= k;
  std::cout << "If new dimensions (Width = " << width << "; Height = "
    << height << ") are OK then scaling rectangle completed successfully\n";
}

lutsaj::Shape::ShapePtr lutsaj::Rectangle::clone() const
{
  return std::make_shared< lutsaj::Rectangle >(*this);
}
