#include <boost/test/unit_test.hpp>

#include "functions.hpp"

BOOST_AUTO_TEST_CASE(isNumberTest)
{
  BOOST_CHECK(lutsaj::isNumber("666"));
  BOOST_CHECK(!lutsaj::isNumber("6a6a6a6"));
  BOOST_CHECK(!lutsaj::isNumber("7_7"));
  BOOST_CHECK(!lutsaj::isNumber("7 7"));
  BOOST_CHECK(!lutsaj::isNumber("a b_"));
}
