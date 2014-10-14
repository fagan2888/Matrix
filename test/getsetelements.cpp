#include<iostream>
#include<vector>
#include<stdexcept>
#include"test.hpp"
#define TYPE double

int main(int argc, char *argv[]) {

	Matrix<TYPE> b;
	Matrix<TYPE> b1(4, 1);
	Matrix<TYPE> b2(1, 4);
	Matrix<TYPE> b3(4, 4);
	TYPE **a1; 
	TYPE **a2;
	TYPE **a3;
	std::vector<bool> success;
	int numtests = 4;
	int testindex = 0;

	for(int i = 0; i < numtests; ++i) 
		success.push_back(true);

	try {
		test::malloc2d<TYPE>(a1, 4, 1);
		test::malloc2d<TYPE>(a2, 1, 4);
		test::malloc2d<TYPE>(a3, 4, 4);
	}
	catch (std::exception &ex) {
		std::cout << "Caught Exception" << ex.what() << " in memory allocation" << std::endl;
	}

	try {
		test::inittestmatrix<TYPE>(a1, 4, 1);
		test::inittestmatrix<TYPE>(a2, 1, 4);
		test::inittestmatrix<TYPE>(a3, 4, 4);
	} catch (std::exception &ex) {
		std::cout << "Caught Exception" << ex.what() << " initialising matrices" << std::endl;
	}
	
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
		std::cout << "Matrix b " << e.what() << std::endl;
	}
	try{
		test::inittestMatrix(b1);
	}
	catch(std::exception &e){
		std::cout << "Matrix b1 " <<e.what() << std::endl;	
	}

	try{
		test::inittestMatrix(b2);	
	}
	catch(std::exception &e){
		std::cout << "Matrix b2 " << e.what() << std::endl;	
	}

	try{
		test::inittestMatrix(b3);	
	}
	catch(std::exception &e){
		std::cout <<	"Matrix b3 " << e.what() << std::endl;	
	}

	std::cout << "Done" << std::endl;
	std::cout << "Getting elements and comparing to originals" << std::endl;
	
	try{
		b(0, 0) = 1.0;
		if(b(0, 0) != 1.0) {
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for base constructor (1 x 1) Failed"));
		}
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;	
	}

	try{
		if(!test::compare(b1, a1, b1.rows(), b1.cols())) {
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 1 (4 x 1) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}


	try{
		if(!test::compare(b2, a2, b2.rows(), b2.cols())) { 
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 2 (1 x 4) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		if(!test::compare(b3, a3, b3.rows(), b3.cols())) { 
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 3 (4 x 4) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	for(std::vector<bool>::iterator it = success.begin(); it != success.end(); ++it) {
		if(*it)
			std::cout << "Test " << std::distance(success.begin(), it) <<" was successful" << std::endl;
		else
			std::cout << "Tests " << std::distance(success.begin(), it) << " failed" << std::endl;	
	}

	//Cleaning up 2d pointers 
	test::dealloc2d(a1, 1, 4);
	test::dealloc2d(a2, 4, 1);
	test::dealloc2d(a3, 4, 4);
		
	return 0;
}
