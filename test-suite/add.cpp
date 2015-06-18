#include<iostream>
#include<vector>
#include<stdexcept>
#include"test.hpp"
#define TYPE double

int main(int argc, char *argv[]) {

	Matrix<TYPE> b1(4, 1);
	Matrix<TYPE> b2(1, 4);
	Matrix<TYPE> b3(4, 4);
	Matrix<TYPE> ansMatrix1;
	Matrix<TYPE> ansMatrix2;
	Matrix<TYPE> ansMatrix3;
	
	TYPE **a1; 
	TYPE **a2;
	TYPE **a3;
	TYPE **ans1; 
	TYPE **ans2;
	TYPE **ans3;

	std::vector<bool> success;
	int numtests = 4;
	int testindex = 0;
    TYPE tol = 1e-06;

	Matrix<TYPE> tmp;

	for(int i = 0; i < numtests; ++i) 
		success.push_back(true);

	try {
		test::malloc2d<TYPE>(a1, 4, 1);
		test::malloc2d<TYPE>(a2, 1, 4);
		test::malloc2d<TYPE>(a3, 4, 4);
		test::malloc2d<TYPE>(ans1, 4, 1);
		test::malloc2d<TYPE>(ans2, 1, 4);
		test::malloc2d<TYPE>(ans3, 4, 4);
	
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
		test::inittestMatrix(b1);
	}
	catch(std::exception &e){
		std::cout << "Matrix b1 " <<e.what() << std::endl;	
	}
	try{
		test::inittestMatrix(b2);	
	}
	catch(std::exception &e){
		std::cout << "Matrix b2 " <<e.what() << std::endl;	
	}
	try{
		test::inittestMatrix(b3);	
	}
	catch(std::exception &e){
		std::cout <<"Matrix b3 " << e.what() << std::endl;	
	}


    try {
        test::add2d(a1, a1, ans1, 4, 1);
	} 
	catch(std::exception &e){
		std::cout <<"Matrix ans1 " << e.what() << std::endl;	
	}

    try {
        test::add2d(a2, a2, ans2, 1, 4);
	} 
	catch(std::exception &e){
		std::cout <<"Matrix ans1 " << e.what() << std::endl;	
	}
    
    try {
        test::add2d(a3, a3, ans3, 4, 4);
	} 
	catch(std::exception &e){
		std::cout <<"Matrix ans1 " << e.what() << std::endl;	
	}
	

    try {
        ansMatrix1 = b1 + b1;
    } 
	catch(std::exception &e){
		std::cout <<"Matrix ans1 " << e.what() << std::endl;	
	}

	try {
		ansMatrix2 = b2 + b2;
	} 
	catch(std::exception &e){
		std::cout <<"Matrix ans2 " << e.what() << std::endl;	
	}

	try {
		ansMatrix3 = b3 + b3;
	} 
	catch(std::exception &e){
		std::cout <<"Matrix ans3 " << e.what() << std::endl;	
	}

	std::cout << "Done" << std::endl;
	std::cout << "Getting elements and comparing to originals" << std::endl;
	
	
	try{
		if(!test::compare(ansMatrix1, ans1, ansMatrix1.rows(), ansMatrix1.cols(), tol)) {
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 1 (4 x 1) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}


	try{
		if(!test::compare(ansMatrix2, ans2, ansMatrix2.rows(), ansMatrix2.cols(), tol)) { 
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 2 (1 x 4) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		if(!test::compare(ansMatrix3, ans3, ansMatrix3.rows(), ansMatrix3.cols(), tol)) { 
			success[testindex] = false;
			++testindex;
			throw std::runtime_error(std::string("Test for Matrix 3 (4 x 4) Failed"));
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	for(std::vector<bool>::iterator it = success.end(); it != success.begin(); --it) {
		if(*it)
			std::cout << "Test " << std::distance(success.begin(), it) <<" was successful" << std::endl;
		else
			std::cout << "Test " << std::distance(success.begin(), it) << " failed" << std::endl;	
	}

	//Cleaning up 2d pointers 
	test::dealloc2d(a1, 1, 4);
	test::dealloc2d(a2, 4, 1);
	test::dealloc2d(a3, 4, 4);	
    test::dealloc2d(ans1, 1, 4);
	test::dealloc2d(ans2, 4, 1);
	test::dealloc2d(ans3, 4, 4);	
	
    return 0;
}
