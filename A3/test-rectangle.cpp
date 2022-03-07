#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(Rectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  double width = 7;
  double height = 2;
  lutsaj::point_t initPos{0, 0};
  lutsaj::point_t newPos{11, 1};
  lutsaj::Rectangle rect(width, height, initPos);
  double oldPosX = rect.getFrameRect().pos.x;
  double oldPosY = rect.getFrameRect().pos.y;
  rect.move(newPos);

  BOOST_CHECK_EQUAL(oldPosX, (newPos.x - 11));
  BOOST_CHECK_EQUAL(oldPosY, (newPos.y - 1));
  BOOST_CHECK_EQUAL(width, rect.getFrameRect().width);
  BOOST_CHECK_EQUAL(height, rect.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  double k = 2;
  double width = 7;
  double height = 2;
  lutsaj::point_t pos{3, -7};
  lutsaj::Rectangle rect(width, height, pos);
  double oldWidthRectangle = rect.getFrameRect().width;
  double oldHeightRectangle = rect.getFrameRect().height;
  rect.scale(k);

  BOOST_CHECK_EQUAL(rect.getFrameRect().width, oldWidthRectangle*k);
  BOOST_CHECK_EQUAL(rect.getFrameRect().height, oldHeightRectangle*k);
}

BOOST_AUTO_TEST_CASE(getAreaRectangle)
{
  double expectedArea = 12;
  double width = 3;
  double height = 4;
  lutsaj::point_t pos{ 0,0 };
  lutsaj::Rectangle rect(width, height, pos);
  double realArea = rect.getArea();
  BOOST_CHECK_EQUAL(expectedArea, realArea);
  rect.move(5, 5);
  realArea = rect.getArea();
  BOOST_CHECK_EQUAL(expectedArea, realArea);
}

BOOST_AUTO_TEST_SUITE_END()
