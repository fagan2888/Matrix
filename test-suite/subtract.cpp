#define BOOST_TEST_MODULE CopySubtractTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (CopySubtractTest) // name of the test suite is stringtest


BOOST_AUTO_TEST_CASE (testsquarematrixcopysubtract)
{
	int m = 4; 
	int n = 4;
	GPUMatrix::Matrix<Real> a(m, n); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a - b;

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			BOOST_CHECK_CLOSE(0.0 , c(i, j), TOL) ;
		}
	}

}
BOOST_AUTO_TEST_CASE (testrowmatrixcopysubtract)
{
	int m = 4; 
	int n = 1;
	GPUMatrix::Matrix<Real> a(m, n); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a - b;

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			BOOST_CHECK_CLOSE(0.0, c(i, j), TOL) ;
		}
	}
}


BOOST_AUTO_TEST_CASE (testcolmatrixcopysubtract)
{
	int m = 1; 
	int n = 4;

    GPUMatrix::Matrix<Real> a(m, n); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a - b;

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			BOOST_CHECK_CLOSE(0.0 , c(i, j), TOL) ;
		}
	}

}
BOOST_AUTO_TEST_SUITE_END()
