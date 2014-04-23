#include<iostream>
#include<Matrix.hpp>

Matrix::Matrix(){
	
	std::cout << "Constructing Matrix" << std::endl;
	nrows = 1;
	ncols = 1;
	allocate();

}

Matrix::Matrix(int nrows_, int ncols_) {

	nrows = nrows_;
	ncols = ncols_;
	allocate();

}

Matrix::~Matrix(){

	std::cout << "De-constructing Matrix" << std::endl;
	deallocate();

}

void Matrix::allocate(){

	matrix = new double[nrows * ncols];

}

void Matrix::deallocate(){
	
	delete[] matrix;

}
