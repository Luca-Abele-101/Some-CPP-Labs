#include <boost/test/unit_test.hpp>

#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(Circle)

BOOST_AUTO_TEST_CASE(moveCircle)
{
  double radius = 3;
  lutsaj::point_t pos{0, 0};
  lutsaj::point_t newPos{3, 3};
  lutsaj::Circle circ(radius, pos);
  double oldPosX = circ.getFrameRect().pos.x;
  double oldPosY = circ.getFrameRect().pos.y;
  circ.move(newPos);

  BOOST_CHECK_EQUAL(oldPosX, newPos.x-3);
  BOOST_CHECK_EQUAL(oldPosY, newPos.y-3);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  double k = 2;
  double radius = 3;
  lutsaj::point_t pos{0, 0};
  lutsaj::Circle circ(radius, pos);
  double oldRadius = circ.getFrameRect().width/2;
  circ.scale(k);

  BOOST_CHECK_EQUAL(circ.getFrameRect().width/2, oldRadius*k);
}

BOOST_AUTO_TEST_CASE(getAreaCircle)
{
  double expectedArea = 12.56;
  double radius = 2;
  lutsaj::point_t pos{ 0,1 };
  lutsaj::Circle circ(radius, pos);
  double realArea = circ.getArea();
  
  BOOST_CHECK_EQUAL(expectedArea, realArea);
}

BOOST_AUTO_TEST_SUITE_END();
