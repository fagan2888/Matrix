#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
#include<stdexcept>
template<class T>class Matrix{
	
	private:
		T *matrix;
		int nrows;
		int ncols;
		std::string type = "Matrix";		
		void allocate() {
			matrix = new T[nrows * ncols];
		};
		void deallocate() {
			delete[] matrix;
		};

	public:
		Matrix(){
#ifdef DBG
			std::cout << "Constructing Matrix" << std::endl;
#endif	
			nrows = 1;
			ncols = 1;
			allocate();
		};

		Matrix(int nrows_, int ncols_){
			nrows = nrows_;
			ncols = ncols_;
			allocate();
		};

		~Matrix(){
#ifdef DBG
			std::cout << "De-constructing Matrix" << std::endl;
#endif	
			deallocate();
		};

		static Matrix multiply(const Matrix &a, const Matrix &b);
		static Matrix add(const Matrix &a, const Matrix &b);
		T &Set(int row, int col) {	
			if(row < 0 || col < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (row >= nrows || col >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return *(matrix + row * ncols + col);
		};

		T Get(int row, int col) {
			if(row < 0 || col < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (row >= nrows || col >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return matrix[row * ncols + col];
		};

		int rows() const{
			return nrows;
		};
		
		int cols() const{
			return ncols;
		};
		Matrix operator * (const Matrix &b);
		Matrix operator + (const Matrix &b);
		T operator () (int i, int j) const{	
			if(i < 0 || j < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (i >= nrows || j >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return matrix[i * ncols + j];
		}

		T &operator () (int i, int j) {	
			if(i < 0 || j < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (i >= nrows || j >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return *(matrix + i * ncols + j);
		}
};

#endif
