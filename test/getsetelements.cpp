#include<iostream>
#include"initialise.hpp"
#define TYPE double

int main(int argc, char *argv[]) {

	Matrix<TYPE> b1;
	Matrix<TYPE> b2(1, 4);
	Matrix<TYPE> b3(4, 4);
	
	
	TYPE **a1; 
	TYPE **ans1;
	TYPE **a2;
	TYPE **ans2;
	TYPE **a3;
	TYPE **ans3;
	
	test::malloc2d(a1, 4, 1);
	test::malloc2d(ans1, 4, 1);
	test::malloc2d(a2, 1, 4);
	test::malloc2d(ans2, 1, 4);
	test::malloc2d(a3, 4, 4);
	test::malloc2d(ans3, 4, 4);


	test::inittestmatrix(a1, 4, 1);
	test::printmatrix(a1, 4, 1);
	
	TYPE **t = new TYPE *[4];
	for(int i = 0; i < 4; i++)
		t[i] = new TYPE[1];
			
	bool success = true;
	std::cout<<"The following tests checks the setting and getting of elements for the Matrix class" << std::endl;
	std::cout<<"Beginning Getter/Setter Tests for following matrices" << std::endl;
	std::cout<< b1.Get(1, 1);
	test::inittestmatrix<TYPE>(t, 4, 1);
	test::inittestmatrix(a2, 1, 4);
	test::inittestmatrix(a3, 4, 4);
		
	std::cout << "Matrix 1 (4 x 1)" << std::endl;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++)
			std::cout << a1[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "Matrix 2 (1 x 4)" << std::endl;

	test::printmatrix(a1, 4, 1);
	test::printmatrix(a1, 1, 4);
	test::printmatrix(a1, 4, 4);
	
	std::cout << "Matrix 3 (4 x 4)" << std::endl;

	std::cout << "\n";
	std::cout << "Setting elements of an object of type Matrix" << std::endl;


	try{
		test::inittestMatrix(b1, 4, 1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	
	}

	try{
		test::inittestMatrix(b1, 1, 4);	
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		test::inittestMatrix(b2, 4, 4);	
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	std::cout << "Done" << std::endl;
	std::cout << "Getting elements and comparing to originals" << std::endl;

	
	try{
		for(int i = 0; i < 1; i++){
			for(int j = 0; j < 4; j++) {
				if(b2.Get(i, j) != a2[i][j]) {
					throw "Test for Matrix 1 (1 x 4) Failed";
					success = false;
				}	
			}
		}
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;	
	}

	try{
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++) {
				if(b3.Get(i, j) != a3[i][j]) {
					throw "Test for Matrix 1 (4 x 4) Failed";
					success = false;
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

	return 0;
}
