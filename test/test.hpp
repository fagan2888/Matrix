#ifndef __TEST_
#define __TEST_

#define FAIL "Test has failed"
#include<iostream>
#include<Matrix.hpp>
class test{

	public:
	test(){
		std::cout << "Initialising Test Data" << std::endl;
	}

	template<class T> static void inittestmatrix(T **&a, int m, int n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				a[i][j] = static_cast<T>(i * n + j);
			}
		}
	}

	template<class T> static void malloc2d(T **&a, int m, int n) {
		
		a = new T *[m];
		for(int i = 0; i < m; i++)
			a[i] = new T[n];  
	}

	template<class T> static void dealloc2d(T **&a, int m, int n) {
	
		for(int i = 0; i < n; i++)
			delete[] a[i];

		delete[] a;
	}
	template<class T> static void inittestMatrix(Matrix<T> &a){
		for(int i = 0; i < a.rows(); i++){
			for(int j = 0; j < a.cols(); j++)
				a(i, j) = static_cast<T>(i * a.cols() + j); 
		}
	}

	template<class T> static void printmatrix(T **&a, int m, int n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++)
				std::cout << a[i][j] << " ";
			std::cout << "\n";
		}
	}
	template<class T> static void printMatrix(Matrix<T> &a) {
		for(int i = 0; i < a.rows(); i++) {
			for(int j = 0; j < a.cols(); j++)
				std::cout << a(i, j) << " ";
			std::cout << "\n";
		}
	}

	template<class T> static void add2d(T **&a, T **&b, T **&c, int m, int n) {
		
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)
				c[i][j] = a[i][j] + b[i][j];
		}

	}
	
	template<class T> static void subtract2d(T **&a, T **&b, T **&c, int m, int n) {
		
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)
				c[i][j] = a[i][j] - b[i][j];
		}

	}
	template<class T> static bool compare(Matrix<T> &a, T** &b, int m, int n){
		if(a.rows() != m || a.cols() != n)
			return false;

		bool success = true;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(b[i][j] != a(i, j))
					success = false;
			}
		}

		return success;
	}
	
};

#endif
