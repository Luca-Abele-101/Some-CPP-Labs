#include <sstream>
#include <boost/test/unit_test.hpp>
#include "point.hpp"

BOOST_AUTO_TEST_SUITE(test_point)

  BOOST_AUTO_TEST_CASE(CorrectPointInput)
  {
    std::string line("(5; -7)");
    std::stringstream sin(line);
    lutsaj::Point point;
    BOOST_CHECK((sin >> point));
  }

  BOOST_AUTO_TEST_CASE(IncorrectPointInput)
  {
    std::string line("(jnd_kd; -=13=-)");
    std::stringstream sin(line);
    lutsaj::Point point;
    BOOST_CHECK(!(sin >> point));
  }

BOOST_AUTO_TEST_SUITE_END()
