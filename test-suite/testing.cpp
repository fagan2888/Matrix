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

    double x;

    std::swap(x, a(0,0));
    std::cout << x << std::endl;
}

int main(int argc, char *argv[]) {



    int row = 256;
    int col = 256;
    int nsamples = 1;
    auto my_shared_ptr = boost::make_shared<double[]>(row * col, 1.0); 
    double *array = new double[row * col];
    
    GPUMatrix::Matrix<TYPE> a(16, 16);

    test::inittestMatrix(a);
    
   
    
    foo(a);
    
    double *tmp;
    tmp = &my_shared_ptr[0];

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
