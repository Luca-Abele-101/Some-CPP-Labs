#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <iostream>

class Circle: public Shape
{
public:
  Circle(double radius, point_t pos);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  double getRadius() const;
  void move(point_t pos) override;
  void move(double dx, double dy) override;

private:
  double radius;
  point_t pos;
};
#endif
