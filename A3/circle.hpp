#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <iostream>

namespace lutsaj
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, point_t pos);

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ShapePtr clone() const override;

  private:
    double radius;
    point_t pos;
  };
}
#endif
