#define BOOST_TEST_MODULE stringtest
#include <boost/test/included/unit_test.hpp>
#include "./str.h"
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (stringtest) // name of the test suite is stringtest



BOOST_AUTO_TEST_CASE (test2)
{
      mystring s;
      s.setbuffer("hello world");
      BOOST_REQUIRE_EQUAL ('h', s[0]); // basic test 
}

BOOST_AUTO_TEST_SUITE_END()
