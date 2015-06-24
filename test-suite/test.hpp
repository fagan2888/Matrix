#ifndef __TEST_
#define __TEST_

#define FAIL "Test has failed"
#include<iostream>
#include<cmath>
#include<Matrix.hpp>

#define Real double
#define TOL 1e-06

class test{

	public:
	test(){
		std::cout << "Initialisingg Test Data" << std::endl;
	}

	template<class T> static void inittestmatrix(T **&a, int row, int col) {
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j) {
				a[i][j] = static_cast<T>(i * row + j);
			}
		}
	}

	template<class T> static void malloc2d(T **&a, int row, int col) {
		
		a = new T *[col];
		for(int i = 0; i < col; ++i)
			a[i] = new T[row];  
	}

	template<class T> static void dealloc2d(T **&a, int row, int col) {
	
		for(int i = 0; i < col; ++i)
			delete[] a[i];

		delete[] a;
	}
	template<class T> static void inittestMatrix(GPUMatrix::Matrix<T> &a){
        for(int i = 0; i < a.cols(); ++i){
			for(int j = 0; j < a.rows(); ++j)
				a(i, j) = static_cast<T>(i * a.rows() + j); 
		}
	}

	template<class T> static void printmatrix(T **&a, int row, int col) {
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j)
				std::cout << a[i][j] << " ";
			std::cout << "\n";
		}
	}
	
	template<class T> static void add2d(T **&a, T **&b, T **&c, int row, int col) {
		
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j)
				c[i][j] = a[i][j] + b[i][j];
		}

	}
	
	template<class T> static void subtract2d(T **&a, T **&b, T **&c, int row, int col) {
		
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j)
				c[i][j] = a[i][j] - b[i][j];
		}

	}
	template<class T> static bool compare(GPUMatrix::Matrix<T> &a, T** &b, int row, int col, double tol){
		if(a.rows() != row || a.cols() != col)
			return false;

		bool success = true;
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j) {
				if(std::abs(b[i][j] - a(i, j)) > tol)
					success = false;
			}
		}

		return success;
	}
	
};

#endif
