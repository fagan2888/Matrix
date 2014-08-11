#include<iostream>
#include<Matrix.hpp>

/*template<class T> void Matrix<T>::allocate(){

	matrix = new T[nrows * ncols];

}

template<class T> void Matrix<T>::deallocate(){
	
	delete[] matrix;

}

template<class T> int Matrix<T>::rows() const{
	return nrows;
}

template<class T> int Matrix<T>::cols() const{
	return ncols;
}

template<class T> T& Matrix<T>::Set(int i, int j){

	return *(matrix + i * ncols + j);
}

template<class T> T Matrix<T>::Get(int i, int j) {

	if(i < 0 || j < 0)
		throw "Elements cannot be less than 0";

	return matrix[i * ncols + j];

}*/

template<class T> Matrix<T> Matrix<T>::multiply(const Matrix &a, const Matrix &b){

	if(a.cols() != b.rows())
		throw "Matrix dimensions are not compatible for multiplication";
	
	Matrix c(a.rows(), b.cols());

	return c;

}

template<class T> Matrix<T> Matrix<T>::add(const Matrix &a, const Matrix &b) {

	if((a.cols() != b.cols()) && (a.rows() != b.rows()))
		throw "Matrix dimensions are not compatible for addition";

	Matrix c(a.rows(), b.cols());


}
template<class T> Matrix<T> Matrix<T>::operator * (const Matrix &b) {
	multiply(*this, b);
}

template<class T> Matrix<T> Matrix<T>::operator + (const Matrix &b) {
	add(*this, b);
}

