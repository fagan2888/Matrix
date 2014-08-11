#include<iostream>
#include<stdexcept>
#include"initialise.hpp"
#define TYPE double

int main(int argc, char *argv[]) {

	Matrix<TYPE> b;
	Matrix<TYPE> b1(4, 1);
	Matrix<TYPE> b2(1, 4);
	Matrix<TYPE> b3(4, 4);
		
	TYPE **a1; 
	TYPE **ans1;
	TYPE **a2;
	TYPE **ans2;
	TYPE **a3;
	TYPE **ans3;

	try {
		test::malloc2d<TYPE>(a1, 4, 1);
		test::malloc2d<TYPE>(ans1, 4, 1);
		test::malloc2d<TYPE>(a2, 1, 4);
		test::malloc2d<TYPE>(ans2, 1, 4);
		test::malloc2d<TYPE>(a3, 4, 4);
		test::malloc2d<TYPE>(ans3, 4, 4);
	}
	catch (std::exception &ex) {
		std::cout << "Caught Exception" << ex.what() << " in memory allocation" << std::endl;
	}

	test::inittestmatrix<TYPE>(a1, 4, 1);
	test::inittestmatrix<TYPE>(a2, 1, 4);
	test::inittestmatrix<TYPE>(a3, 4, 4);
			
	bool success = true;
	std::cout<<"The following tests checks the setting and getting of elements for the Matrix class" << std::endl;
	std::cout<<"Beginning Getter/Setter Tests for following matrices" << std::endl;


	
	std::cout << "Matrix 1 (4 x 1)" << std::endl;
	
	test::printmatrix<TYPE>(a1, 4, 1);

	std::cout << "Matrix 2 (1 x 4)" << std::endl;

	test::printmatrix<TYPE>(a2, 1, 4);
	
	std::cout << "Matrix 3 (4 x 4)" << std::endl;

	test::printmatrix<TYPE>(a3, 4, 4);

	std::cout << "\n";
	std::cout << "Setting elements of an object of type Matrix" << std::endl;

	try{
		test::inittestMatrix(b);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try{
		test::inittestMatrix(b1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		test::inittestMatrix(b2);	
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		test::inittestMatrix(b3);	
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	std::cout << "Done" << std::endl;
	std::cout << "Getting elements and comparing to originals" << std::endl;

	try{
		b.Set(1, 1) = 1.0;
		if(b.Get(1, 1) != 1.0) {
			success = false;
			throw std::runtime_error(std::string("Test for base constructor (1 x 1) Failed"));
		}
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;	
	}

	try{
		for(int i = 0; i < b1.rows(); i++){
			for(int j = 0; j < b1.cols(); j++) {
				if(b1.Get(i, j) != a1[i][j]) {
					success = false;
					throw std::runtime_error(std::string("Test for Matrix 1 (4 x 1) Failed"));
				}	
			}
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}


	try{
		for(int i = 0; i < b2.rows(); i++){
			for(int j = 0; j < b2.cols(); j++) {
				if(b2.Get(i, j) != a2[i][j]) {	
					success = false;
					throw std::runtime_error(std::string("Test for Matrix 1 (1 x 4) Failed"));

				}	
			}
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		for(int i = 0; i < b3.rows(); i++){
			for(int j = 0; j < b3.cols(); j++) {
				if(b3.Get(i, j) != a3[i][j]) {	
					success = false;
					throw std::runtime_error(std::string("Test for Matrix 1 (4 x 4) Failed"));

				}
			}
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}
	
	if(success)
		std::cout << "The tests were successful" << std::endl;
	else
		std::cout << "The tests failed" << std::endl;	
	
	test::dealloc2d(a1, 1, 4);
	test::dealloc2d(a2, 4, 1);
	test::dealloc2d(a3, 4, 4);
	test::dealloc2d(ans1, 1, 4);
	test::dealloc2d(ans2, 4, 1);
	test::dealloc2d(ans3, 4, 4);

	double x = b1(0,0);
	std::cout << x << " " << b1(0, 0) << std::endl;
	x = 43;
	std::cout << x << " " << b1(0, 0) << std::endl;
	for(int i = 0; i < b1.rows(); ++i) {
		for(int j = 0; j < b1.cols(); ++j) 
			std::cout << b1(i, j) << " ";
		std::cout << "\n";
	}

	
	return 0;
}
