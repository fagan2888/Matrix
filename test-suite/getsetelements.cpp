#define BOOST_TEST_MODULE GetSetTest
#include <boost/test/included/unit_test.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (GetSetTest) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (testsquarematrix)
{
	int rows = 4; 
	int cols = 4;
	GPUMatrix::Matrix<Real> a(rows, cols); 

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			a(i , j) = static_cast<Real> (i * rows + j);
            BOOST_CHECK_CLOSE_FRACTION(a(i, j), static_cast<Real> (i * cols + j), TOL);
		}
	}


}

BOOST_AUTO_TEST_CASE (testrowmatrix)
{
	int rows = 4; 
	int cols = 1;
	GPUMatrix::Matrix<Real> a(rows, cols); 

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			a(i , j) = static_cast<Real> (i * cols + j);
			BOOST_CHECK_CLOSE_FRACTION(a(i, j), static_cast<Real> (i * cols + j), TOL);
		}
	}

	

}

BOOST_AUTO_TEST_CASE (testcolmatrix)
{
	int rows = 1; 
	int cols = 4;
	GPUMatrix::Matrix<Real> a(rows, cols); 

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			a(i, j) = static_cast<Real> (i * cols + j);
			BOOST_CHECK_CLOSE_FRACTION(a(i, j), static_cast<Real> (i * cols + j), TOL);
		}
	}

}
BOOST_AUTO_TEST_SUITE_END()
