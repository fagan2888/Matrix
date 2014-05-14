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

	template<class T> static void inittestmatrix(T a[4][1], int m, int n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++)
				a[i][j] = static_cast<T>(i * n + j);
		}
	}

	template<class T> static void inittestMatrix(Matrix<T> a, int m, int n){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				a.Set(i, j) = static_cast<T>(i * n + j); 
		}
	}

	template<class T> static void printMatrix(Matrix<T> a, int m, int n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++)
				std::cout << a[i][j] << " ";
			std::cout << "\n";
		}
	}

	template<class T> static bool compare(Matrix<T> a, T** b, int m, int n){
		if(a.nrows() != m || a.ncols() != n)
			return false;

		bool success = true;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(b[i][j] != a.Get(i, j))
					success = false;
			}
		}

		return success;
	}
	
	private:
};

#endif
