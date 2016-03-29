#include<iostream>
#include<vector>
#include<stdexcept>
#include<boost/smart_ptr/make_shared_array.hpp>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include <boost/timer/timer.hpp>
#include<type_traits>
#include<algorithm>
#include<utility>
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
    GPUMatrix::Matrix<double> * mat = new GPUMatrix::Matrix<double>(row, col);

    
    std::string s = mat->name();
    
    std::cout << s << std::endl;    
    double *array = new double[row * col];

    delete[] array;
    delete mat;
    return 0;
}
