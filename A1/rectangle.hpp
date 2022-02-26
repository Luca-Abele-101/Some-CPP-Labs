#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, point_t pos);

  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t pos) override;
  void move(double dx, double dy) override;

private:
  double width;
  double height;
  point_t pos;
};
#endif
