#include<iostream>
#include<vector>
#include<stdexcept>
//#include <boost/timer/timer.hpp>
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


/*void return_address(int row, int col) {

    auto my_shared_ptr = std::make_shared<double[]>(row * col); 

    //return my_shared_ptr.get();
}*/

int main(int argc, char *argv[]) {

    int row = 256;
    int col = 256;
    int nsamples = 1;
    //auto my_shared_ptr = std::make_shared<double[]>(row * col); 
    GPUMatrix::Matrix<double> * mat = new GPUMatrix::Matrix<double>(row, col);

    std::string s = mat->name();
    
    std::cout << s << std::endl;    

    delete mat;
    return 0;
}
