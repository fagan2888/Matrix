#include<iostream>
#include<vector>
#include<stdexcept>
#include<boost/smart_ptr/make_shared_array.hpp>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include"test.hpp"
#define TYPE double

int main(int argc, char *argv[]) {


	
  ` `auto my_shared_ptr = boost::make_shared<double[]>(32, 1.0); 

    for(int i = 0; i < 32; ++i) { 
        std::cout << *(my_shared_ptr.get() + i) << std::endl;
        *(my_shared_ptr.get() + i) = 21.0;
        std::cout << my_shared_ptr[i] << std::endl;
    }
    


	Matrix<TYPE> b;
	Matrix<TYPE> b1(4, 4);

	TYPE **a1; 
	TYPE **a2;

	test::malloc2d<TYPE>(a1, 4, 1);

	
	try{
		test::inittestMatrix(b);
		std::cout << b;
	} catch(std::exception &e) {
		std::cout << "Matrix b " << e.what() << std::endl;
	}
	try{
		test::inittestMatrix(b1);
		std::cout << b1;
	}
	catch(std::exception &e){
		std::cout << "Matrix b1 " <<e.what() << std::endl;	
	}
	
	b = b1 + b1;

	const Matrix<TYPE> CMat(b);
	double *p;
	p = &b(2,2);
	*p = 21;
	
	std::cout << &(*p) << std::endl;
	std::cout << p << std::endl;
	std::cout << &p << std::endl;
	
	std::cout << "\n";
	std::cout << b;

	return 0;
}
