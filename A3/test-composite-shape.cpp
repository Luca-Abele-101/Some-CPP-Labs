#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lut = lutsaj;

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(moveShapes)
{
  const int size = 2;
  double width = 1;
  double height = 1;
  lut::point_t p1 = {2, 2};
  double radius = 3;
  lut::point_t p2 = {1, 1};
  lut::point_t p3 = {5, 5};

  lut::CompositeShape::ArrayType shapes = std::make_unique< lut::Shape::ShapePtr[] >(size);
  shapes[0] = std::make_shared< lut::Rectangle >(lut::Rectangle(width, height, p1));
  shapes[1] = std::make_shared< lut::Circle >(lut::Circle(radius, p2));

  for (int i = 0; i < size; i++)
  {
    shapes[i]->move(p3);
  }

  lut::point_t realPos = shapes[0]->getFrameRect().pos;
  BOOST_CHECK_EQUAL(realPos.x, p3.x);
  BOOST_CHECK_EQUAL(realPos.y, p3.y);

  realPos = shapes[1]->getFrameRect().pos;
  BOOST_CHECK_EQUAL(realPos.x, p3.x);
  BOOST_CHECK_EQUAL(realPos.y, p3.y);
}

BOOST_AUTO_TEST_CASE(scaleShapes)
{
  const int size = 2;
  const double k = 2;

  double width = 1;
  double height = 2;
  lut::point_t p1 = {0, 0};
  lut::point_t p2 = {1, 1};
  double radius = 2;

  lut::CompositeShape::ArrayType shapes = std::make_unique< lut::Shape::ShapePtr[] >(size);
  shapes[0] = std::make_shared< lut::Rectangle >(lut::Rectangle(width, height, p1));
  shapes[1] = std::make_shared< lut::Circle >(lut::Circle(radius, p2));
  double oldWidthRectangle = shapes[0]->getFrameRect().width;
  double oldHeightRectangle = shapes[0]->getFrameRect().height;
  double oldRadius = shapes[1]->getFrameRect().height/2;
  for (int i = 0; i < size; i++)
  {
    shapes[i]->scale(k);
  }

  BOOST_CHECK_EQUAL(width, oldWidthRectangle);
  BOOST_CHECK_EQUAL(height, oldHeightRectangle);
  BOOST_CHECK_EQUAL(radius, oldRadius);
}


BOOST_AUTO_TEST_SUITE_END()
