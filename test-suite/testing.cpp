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
    
 
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    GPUMatrix::Matrix<TYPE> d(4, 1);
    test::inittestMatrix(d); 
    //GPUMatrix::Matrix<TYPE> e(1, 4); 
    //test::inittestMatrix(e); 

    //auto f = d * e;

    std::cout << d << std::endl;
    //std::cout << e << std::endl;
    //std::cout << c << std::endl;

    {
        boost::timer::auto_cpu_timer t;	
        for(int sample = 0; sample < nsamples; ++sample) {
            for(int i = 0; i < row; ++i) { 
                for(int j = 0; j < col; ++j)    
                    *(my_shared_ptr.get() + i * col + j) = (double)(i * col + j);
            }
        }

    }

    {

        boost::timer::auto_cpu_timer t;	
        
        for(int sample = 0; sample < nsamples; ++sample) {
            for(int i = 0; i < col; ++i) {
                for(int j = 0; j < row; ++j)  
                    *(my_shared_ptr.get() + i * row + j) = (double)(i * row + j);
            }
        }    
    }

    {

        boost::timer::auto_cpu_timer t;	
        
        for(int sample = 0; sample < nsamples; ++sample) {
            for(int i = 0; i < row; ++i) {
                for(int j = 0; j < col; ++j)  
                    *(my_shared_ptr.get() + j * row + i) = (double)(j * row + i);
            }
        }
    }



        delete[] array;

	return 0;
}
