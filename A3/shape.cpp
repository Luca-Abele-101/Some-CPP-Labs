#include "shape.hpp"
#include <iostream>

double lutsaj::getX(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().pos.x;
}

double lutsaj::getY(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().pos.y;
}

double lutsaj::getWidth(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().width;
}

double lutsaj::getHeight(const Shape::ShapePtr& shp)
{
  return shp->getFrameRect().height;
}
