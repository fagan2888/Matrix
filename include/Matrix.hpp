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

		void multiply(const Matrix &a, const Matrix &b, Matrix &c){
			if(a.cols() != b.rows())
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for multiplication"));
		}
		
		void add(Matrix &a, const Matrix &b, Matrix &c) {
			
			if((a.cols() != b.cols()) && (a.rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));
			
			for(int i = 0; i < a.rows(); ++i) {
				for(int j = 0; j < a.cols(); ++j) {
					c(i, j) = a(i, j) + b(i, j);
				}
			}
		}

		void subtract(const Matrix &a, const Matrix &b, Matrix &c) {
			
			if((a.cols() != b.cols()) && (a.rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));
			
			for(int i = 0; i < a.rows(); ++i) {
				for(int j = 0; j < a.cols(); ++j) {
					c(i, j) = a(i, j) + b(i, j);
				}
			}
		}

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

		int rows() const{
			return nrows;
		};
		
		int cols() const{
			return ncols;
		};
		
		T operator () (int i, int j) const{	
			if(i < 0 || j < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (i >= nrows || j >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return Get(i, j);
		}

		T &operator () (int i, int j) {	
			if(i < 0 || j < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (i >= nrows || j >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return Set(i, j);
		}

		Matrix operator * (const Matrix &b) {	

			Matrix c;
			multiply(*this, b, c);
			return c;
		}

		Matrix operator + (const Matrix &b) {	
			
			if((this->cols() != b.cols()) && (this->rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));
			
			Matrix c(b.rows(), b.cols());
			
			//add(this, b, c);
			
			return c;
		}

		Matrix operator - (const Matrix &b) {
			
			if((this->cols() != b.cols()) && (this->rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));
			
			Matrix c(b.rows(), b.cols());
			
			subtract(*this, b, c);
			
			return c;
		}

};
#endif
