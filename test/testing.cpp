#include<iostream>
#include<vector>
#include<stdexcept>
#include"test.hpp"
#define TYPE double

int main(int argc, char *argv[]) {

	Matrix<TYPE> b;
	Matrix<TYPE> b1(4, 4);
		
	try{
		test::inittestMatrix(b);
		test::printMatrix(b);
	} catch(std::exception &e) {
		std::cout << "Matrix b " << e.what() << std::endl;
	}
	try{
		test::inittestMatrix(b1);
		test::printMatrix(b1);
	}
	catch(std::exception &e){
		std::cout << "Matrix b1 " <<e.what() << std::endl;	
	}
	
	std::cout << "Start = " << std::endl; 
	b = b1 + b1;

	std::cout << "END = " << std::endl;	

	test::printMatrix(b);
	return 0;
}
