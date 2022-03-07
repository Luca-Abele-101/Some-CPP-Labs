#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <iostream>

namespace lutsaj
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, point_t pos);

    double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    double getWidth() const;
    double getHeight() const;
    void scale(double k) override;
    ShapePtr clone() const override;

  private:
    double width;
    double height;
    point_t pos;
  };
}
#endif
