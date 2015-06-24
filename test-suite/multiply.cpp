#define BOOST_TEST_MODULE CopyAddTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (MultiplyTest) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (testsquarematrixmultiply)
{
	int row = 4; 
	int col = 4;	
    Real answer[16] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169};

    GPUMatrix::Matrix<Real> a(row, col); 
    test::inittestMatrix(a);
    GPUMatrix::Matrix<Real> b(a);

    GPUMatrix::Matrix<Real> c;

    c = a * b;

	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
            BOOST_CHECK_CLOSE(answer[i * row + j] , c(i, j), TOL) ;
		}
	}

}
BOOST_AUTO_TEST_CASE (TestRowMatrixMultiply)
{
	int row = 4; 
	int col = 1;
	GPUMatrix::Matrix<Real> a(row, col); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a * b;

	for(int i = 0; i < col; ++i) {
		for(int j = 0; j < row; ++j) {
            BOOST_CHECK_CLOSE(static_cast<Real>(i * row + j) * static_cast<Real>(i * row + j) , c(i, j), TOL) ;
		}
	}
}

BOOST_AUTO_TEST_CASE (TestColMatrixMultiply)
{
	int col = 1; 
	int row = 4;

    GPUMatrix::Matrix<Real> a(row, col); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a * b;

	for(int i = 0; i < col; ++i) {
		for(int j = 0; j < row; ++j) {
            BOOST_CHECK_CLOSE(static_cast<Real>(i * row + j) * static_cast<Real>(i * row + j) , c(i, j), TOL) ;
		}
	}

}
BOOST_AUTO_TEST_SUITE_END()
