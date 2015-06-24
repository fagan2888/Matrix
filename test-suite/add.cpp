#define BOOST_TEST_MODULE CopyAddTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (CopyAddTest) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (testsquarematrixcopyadd)
{
	int row = 4; 
	int col = 4;
	GPUMatrix::Matrix<Real> a(row, col); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a + b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

	for(int i = 0; i < col; ++i) {
		for(int j = 0; j < row; ++j) {
            BOOST_CHECK_CLOSE(2.0 * a(i, j), c(i, j), TOL) ;
		}
	}

}
/*BOOST_AUTO_TEST_CASE (testrowmatrixcopyadd)
{
	int row = 4; 
	int col = 1;
	GPUMatrix::Matrix<Real> a(row, col); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a + b;

	for(int i = 0; i < col; ++i) {
		for(int j = 0; j < row; ++j) {
			BOOST_CHECK_CLOSE(2.0 * a(i, j), c(i, j), TOL) ;
		}
	}
}

BOOST_AUTO_TEST_CASE (testcolmatrixcopyadd)
{
	int col = 1; 
	int row = 4;

    GPUMatrix::Matrix<Real> a(row, col); 
    
    test::inittestMatrix(a);

    GPUMatrix::Matrix<Real> b(a);
    GPUMatrix::Matrix<Real> c;

    c = a + b;

	for(int i = 0; i < col; ++i) {
		for(int j = 0; j < row; ++j) {
			BOOST_CHECK_CLOSE(2.0 * a(i, j), c(i, j), TOL) ;
		}
	}

}*/
BOOST_AUTO_TEST_SUITE_END()
