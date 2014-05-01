#include<iostream>
#include<Matrix.hpp>

Matrix::Matrix(){

#ifdef DBG
	std::cout << "Constructing Matrix" << std::endl;
#endif	
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

#ifdef DBG
	std::cout << "De-constructing Matrix" << std::endl;
#endif	
	deallocate();

}

void Matrix::allocate(){

	matrix = new double[nrows * ncols];

}

void Matrix::deallocate(){
	
	delete[] matrix;

}

int Matrix::rows() const{
	return nrows;
}

int Matrix::cols() const{
	return ncols;
}

double& Matrix::Set(int i, int j){

	return *(matrix + i * ncols + j);
}

double Matrix::Get(int i, int j) {

	if(i < 0 || j < 0)
		throw "Elements cannot be less than 0";

	return matrix[i * ncols + j];

}
Matrix Matrix::multiply(const Matrix &a, const Matrix &b){

	if(a.cols() != b.rows())
		throw "Matrix dimensions are not compatible for multiplication";
	
	Matrix c(a.rows(), b.cols());

	return c;

}

Matrix Matrix::add(const Matrix &a, const Matrix &b) {

	if((a.cols() != b.cols()) && (a.rows() != b.rows()))
		throw "Matrix dimensions are not compatible for addition";

	Matrix c(a.rows(), b.cols());


}
Matrix Matrix::operator * (const Matrix &b) {

	multiply(*this, b);
}

Matrix Matrix::operator + (const Matrix &b) {

	add(*this, b);
}

