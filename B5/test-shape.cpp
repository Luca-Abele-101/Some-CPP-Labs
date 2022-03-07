#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(test_shape)

  BOOST_AUTO_TEST_CASE(IncorrectShapeInput)
  {
    std::string str("3 (     ;8) (5;) (ddgg;dr_fks)");
    std::stringstream sin(str);
    lutsaj::Shape shp;
    BOOST_CHECK(!(sin >> shp));
  }

BOOST_AUTO_TEST_SUITE_END()
