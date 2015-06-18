#define BOOST_TEST_MODULE GetSetTest
#include <boost/test/included/unit_test.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (GetSetTest) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (test1)
{
	int m = 4; 
	int n = 4;
	GPUMatrix::Matrix<Real> a(m, n); 

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			a(i , j) = static_cast<Real> (i * n + j);
			BOOST_CHECK(a(i, j) == static_cast<Real> (i * n + j));
		}
	}

	

}
BOOST_AUTO_TEST_CASE (test2)
{
	int m = 4; 
	int n = 1;
	GPUMatrix::Matrix<Real> a(m, n); 

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			a(i , j) = static_cast<Real> (i * n + j);
			BOOST_CHECK(a(i, j) == static_cast<Real> (i * n + j));
		}
	}

	

}

BOOST_AUTO_TEST_CASE (test3)
{
	int m = 1; 
	int n = 4;
	GPUMatrix::Matrix<Real> a(m, n); 

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			a(i , j) = static_cast<Real> (i * n + j);
			BOOST_REQUIRE_EQUAL(a(i, j), static_cast<Real> (i * n + j));
		}
	}

}
BOOST_AUTO_TEST_SUITE_END()
