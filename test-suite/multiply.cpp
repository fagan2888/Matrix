#define BOOST_TEST_MODULE CopyAddTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "test.hpp"

BOOST_AUTO_TEST_SUITE (MultiplyTest) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (testsquarematrixmultiply)
{
	int row = 4; 
	int col = 4;	
    Real answer[16] = {56, 62, 68, 74, 152, 174, 196, 218, 248, 286, 324, 362, 344, 398, 452, 506};

    GPUMatrix::Matrix<Real> a(row, col); 
    test::inittestMatrix(a);
    GPUMatrix::Matrix<Real> b(a);

    GPUMatrix::Matrix<Real> c;

    c = a * b;

#ifdef DBG
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
#endif

	for(int i = 0; i < c.rows(); ++i) {
		for(int j = 0; j < c.cols() ; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(c(i, j), answer[i * col + j], TOL);
		}
	}

}

BOOST_AUTO_TEST_CASE (TestRowMatrixMultiply)
{
	int row = 4; 
	int col = 1;
	GPUMatrix::Matrix<Real> a(row, col); 
    GPUMatrix::Matrix<Real> b(col, row);
    Real answer[16] = {0, 0, 0, 0, 0, 1, 2, 3, 0, 2, 4, 6, 0, 3, 6, 9};
    
    test::inittestMatrix(a);
    test::inittestMatrix(b);
    
    GPUMatrix::Matrix<Real> c(4, 4);

    c = a * b;

#ifdef DBG
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
#endif 

    for(int i = 0; i < c.rows(); ++i) {
		for(int j = 0; j < c.cols(); ++j) {	
			BOOST_CHECK_CLOSE_FRACTION(c(i, j), answer[i * c.cols() + j], TOL);
		}
	}
}

BOOST_AUTO_TEST_CASE (TestColMatrixMultiply)
{
	int row = 1; 
	int col = 4;

    GPUMatrix::Matrix<Real> a(row, col);  
    GPUMatrix::Matrix<Real> b(col, row); 
    Real answer[1] = {14};
    test::inittestMatrix(a);
    test::inittestMatrix(b);
   
    //Test Copy Constructor
    GPUMatrix::Matrix<Real> c(a * b);


#ifdef DBG
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
#endif 

	for(int i = 0; i < c.rows(); ++i) {
		for(int j = 0; j < c.cols(); ++j) {	
			BOOST_CHECK_CLOSE_FRACTION(c(i, j), answer[i * c.cols() + j], TOL);
        }
	}

}
//Check exceptions thrown correctly 
//Check Row matrix multiplication
BOOST_AUTO_TEST_CASE (TestThrowRowMatrixMultiply) {
 
	int row = 1; 
	int col = 4;

    GPUMatrix::Matrix<Real> a(row, col);  
    
    BOOST_CHECK_THROW(a * a, std::exception);
}

//Check Col matrix multiplication
BOOST_AUTO_TEST_CASE (TestThrowColMatrixMultiply) {
 
	int row = 4; 
	int col = 1;
	
    GPUMatrix::Matrix<Real> a(row, col); 
    
    BOOST_CHECK_THROW(a * a, std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
