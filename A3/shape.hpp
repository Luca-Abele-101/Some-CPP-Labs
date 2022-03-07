#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace lutsaj
{
  class Shape
  {
  public:
    using ShapePtr = std::shared_ptr < Shape >;
    virtual ShapePtr clone() const = 0;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double x, double y) = 0;
    virtual void move(point_t pos) = 0;
    virtual void scale(double k) = 0;

    virtual ~Shape() = default;
  };
  double getX(const Shape::ShapePtr& shp);
  double getY(const Shape::ShapePtr& shp);
  double getWidth(const Shape::ShapePtr& shp);
  double getHeight(const Shape::ShapePtr& shp);
}
#endif
