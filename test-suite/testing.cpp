#include<iostream>
#include<vector>
#include<stdexcept>
#include<boost/smart_ptr/make_shared_array.hpp>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include <boost/timer/timer.hpp>
#include<type_traits>
#include"test.hpp"
#define TYPE double


void foo(const GPUMatrix::Matrix<TYPE> &a) {

    double *x;
    GPUMatrix::Matrix<TYPE> tmp(a);
    
    std::cout << &tmp(4, 4) << std::endl;
}


TYPE * return_address(int row, int col) {

    auto my_shared_ptr = boost::make_shared<double[]>(row * col, 1.0); 

    return my_shared_ptr.get();
}

int main(int argc, char *argv[]) {



    int row = 256;
    int col = 256;
    int nsamples = 1;
    auto my_shared_ptr = boost::make_shared<double[]>(row * col, 1.0); 
    double *array = new double[row * col];
   

    GPUMatrix::Matrix<TYPE> a(4, 4);
    test::inittestMatrix(a); 
    GPUMatrix::Matrix<TYPE> b(a);
 

    auto c = a * b;

    std::cout << c << std::endl;

    delete[] array;

	return 0;
}
