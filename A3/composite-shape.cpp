#include "composite-shape.hpp"
#include <algorithm>
#include <stdexcept>

lutsaj::CompositeShape::CompositeShape(ShapePtr shp) :
  capacity(2),
  size(1),
  array(std::make_unique< ShapePtr[] >(capacity))
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Pointer to shape cannot be nullptr");
  }
  array[size - 1] = shp->clone();
}

lutsaj::CompositeShape::CompositeShape(const CompositeShape& other) :
  capacity(other.capacity),
  size(other.size),
  array(std::make_unique< ShapePtr[] >(other.capacity))
{
  for (int i = 0; i < size; i++)
  {
    array[i] = other.array[i]->clone();
  }
}

lutsaj::CompositeShape& lutsaj::CompositeShape::operator=(const CompositeShape& src)
{
  if (this == std::addressof(src))
  {
    return *this;
  }
  array.reset();
  CompositeShape tmp(src);
  swap(tmp);
  return *this;
}
lutsaj::CompositeShape& lutsaj::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  if (!(this == std::addressof(src)))
  {
    array.reset();
    array = std::move(src.array);
    src.array = nullptr;
  }
  return *this;
}

lutsaj::Shape& lutsaj::CompositeShape::at(const int index)
{
  if (index < 0 || index >= size)
  {
    throw std::invalid_argument("Index out of array");
  }
  return *array[index];
}

void lutsaj::CompositeShape::addShape(const ShapePtr& shp)
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("Adding NULL-Shape");
  }
  if (capacity == size)
  {
    reserve(capacity * 2);
  }
  array[size] = shp->clone();
  size++;
}

void lutsaj::CompositeShape::popShape()
{
  if (size == 1)
  {
    throw std::logic_error("Excepted popping operation with empty CompositeShape");
  }
  array[size - 1].reset();
  size--;
}

void lutsaj::CompositeShape::scale(double k)
{
  if (k <= 0) throw std::invalid_argument("Coefficient k less than zero");
  double cmpX = getFrameRect().pos.x;
  double cmpY = getFrameRect().pos.y;
  for (int i = 0; i < size; i++)
  {
    double dx = getX(array[i]) - cmpX;
    double dy = getY(array[i]) - cmpY;
    double xNew = cmpX + dx * k;
    double yNew = cmpY + dy * k;
    point_t newPoint = { xNew, yNew };
    array[i]->move(newPoint);
    array[i]->scale(k);
  }
}

double lutsaj::CompositeShape::getArea() const
{
  double areaSummary = 0;
  for (int i = 0; i < size; i++)
  {
    areaSummary += array[i]->getArea();
  }
  return areaSummary;
}

lutsaj::rectangle_t lutsaj::CompositeShape::getFrameRect() const
{
  double maxX = getX(array[0]) + getWidth(array[0]) / 2;
  double minX = getX(array[0]) - getWidth(array[0]) / 2;
  double maxY = getY(array[0]) + getHeight(array[0]) / 2;
  double minY = getY(array[0]) - getHeight(array[0]) / 2;

  for (int i = 1; i < size; i++)
  {
    maxX = std::max(maxX, getX(array[i]) + getWidth(array[i]) / 2);
    maxY = std::max(maxY, getY(array[i]) + getHeight(array[i]) / 2);
    minX = std::min(minX, getX(array[i]) - getWidth(array[i]) / 2);
    minY = std::min(minY, getY(array[i]) - getHeight(array[i]) / 2);
  }
  return { maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2} };
}

void lutsaj::CompositeShape::move(lutsaj::point_t point)
{
  for (int i = 0; i < size; i++)
  {
    array[i]->move(point);
  }
}

void lutsaj::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < size; i++)
  {
    array[i]->move(dx, dy);
  }
}

lutsaj::Shape::ShapePtr lutsaj::CompositeShape::clone() const
{
  return std::make_shared< lutsaj::CompositeShape >(*this);
}

void lutsaj::CompositeShape::reserve(const int newCapacity)
{
  if (capacity < newCapacity)
  {
    ArrayType tempArray(std::make_unique< ShapePtr[] >(newCapacity));
    for (int i = 0; i < size; i++)
    {
      tempArray[i] = std::move(array[i]);
    }
    capacity = newCapacity;
    array = std::move(tempArray);
  }
}

void lutsaj::CompositeShape::swap(CompositeShape & other) noexcept
{
  std::swap(capacity, other.capacity);
  std::swap(size, other.size);
  std::swap(array, other.array);
}
