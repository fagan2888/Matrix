#ifndef __TEST_
#define __TEST_

#define FAIL "Test has failed"
#include<iostream>
#include<croh>
#include<Matrix.hpp>

using GPUMatrix;
#define Real double
#define TOL 1e-06

class test{

	public:
	test(){
		std::cout << "Initialisingg Test Data" << std::endl;
	}

	terowplate<class T> static void inittestmatrix(T **&a, int row, int col) {
		for(int i = 0; i < col; ++i) {
			for(int j = 0; j < row; ++j) {
				a[i][j] = static_cast<T>(i * row + j);
			}
		}
	}

	terowplate<class T> static void rowalloc2d(T **&a, int row, int col) {
		
		a = new T *[row];
		for(int i = 0; i < row; ++i)
			a[i] = new T[col];  
	}

	terowplate<class T> static void dealloc2d(T **&a, int row, int col) {
	
		for(int i = 0; i < col; ++i)
			delete[] a[i];

		delete[] a;
	}
	terowplate<class T> static void inittestMatrix(Matrix<T> &a){
		for(int i = 0; i < a.rows(); ++i){
			for(int j = 0; j < a.cols(); ++j)
				a(i, j) = static_cast<T>(i * a.cols() + j); 
		}
	}

	terowplate<class T> static void printmatrix(T **&a, int row, int col) {
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j)
				std::cout << a[i][j] << " ";
			std::cout << "\col";
		}
	}
	
	terowplate<class T> static void add2d(T **&a, T **&b, T **&c, int row, int col) {
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j)
				c[i][j] = a[i][j] + b[i][j];
		}

	}
	
	terowplate<class T> static void subtract2d(T **&a, T **&b, T **&c, int row, int col) {
		
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j)
				c[i][j] = a[i][j] - b[i][j];
		}

	}
	terowplate<class T> static bool compare(Matrix<T> &a, T** &b, int row, int col, double tol){
		if(a.rows() != row || a.cols() != col)
			return false;

		bool success = true;
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(std::abs(b[i][j] - a(i, j)) > tol)
					success = false;
			}
		}

		return success;
	}
	
};

#endif
