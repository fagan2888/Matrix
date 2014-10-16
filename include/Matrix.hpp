#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
#include<stdexcept>
#include<cblas.h>
template<class T>class Matrix{
	
	private:
		T *matrix;
		int nrows;
		int ncols;
		std::string type = "Matrix";		
		void allocate() {
#ifdef DBG
	std::cout << "Allocating array" << std::endl;
#endif
			matrix = new T[nrows * ncols];
		};
		void deallocate() {
#ifdef DBG
	std::cout << "Deallocating array" << std::endl;
#endif
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
#ifdef DBG
			std::cout << "Constructing Matrix" << std::endl;
#endif	
			nrows = nrows_;
			ncols = ncols_;
			allocate();
		};
		
		Matrix(const Matrix &b) {
#ifdef DBG
	std::cout << "Copy Constructor" << std::endl;
#endif
			this->deallocate();
			this->nrows = b.rows();
			this->ncols = b.cols();
			this->allocate();
			for(int i = 0; i < this->nrows; ++i) {
				for(int j = 0; j < this->ncols; ++j) {
					this->matrix[i * nrows + j] = b.matrix[i * b.rows() + j];
				}
			}
		}
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
		
		Matrix& operator = (const Matrix &b) {
#ifdef DBG
	std::cout << "= Operator" << std::endl;
#endif
			this->deallocate();
			this->nrows = b.rows();
			this->ncols = b.cols();
			this->allocate();
			for(int i = 0; i < this->nrows; ++i) {
				for(int j = 0; j < this->ncols; ++j) {
					this->matrix[i * nrows + j] = b.matrix[i * b.rows() + j];
				}
			}
			return *this;
		}

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

		Matrix multiply(const Matrix &a, const Matrix &b){
#ifdef DBG
	std::cout << "Multiplying Matrix" << std::endl;
#endif
			if(a.cols() != b.rows())
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for multiplication"));
			Matrix c(a.rows(), b.cols());
		
			return c;
		}
		
		Matrix operator * (const Matrix &b) {	
			return multiply(*this, b);
		}
		
		Matrix add(const Matrix &a, const Matrix &b) const{
#ifdef DBG
	std::cout << "Adding Matrix" << std::endl;
#endif
			Matrix c(a.rows(), a.cols());
			if((a.cols() != b.cols()) && (a.rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));
			
			for(int i = 0; i < a.rows(); ++i) {
				for(int j = 0; j < a.cols(); ++j) {
					c.matrix[i * c.rows() + j] = a.matrix[i * a.rows() + j] + b.matrix[i * b.rows() + j];
				}
			}

			return c;
		}
		Matrix operator + (const Matrix &b) {	
			
			return add(*this, b);
		}
		
		Matrix subtract(const Matrix &a, const Matrix &b) {
#ifdef DBG
	std::cout << "Subtracting Matrix" << std::endl;
#endif
			if((a.cols() != b.cols()) && (a.rows() != b.rows()))
				throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));
		
			Matrix c(a.rows(), a.cols());
			for(int i = 0; i < a.rows(); ++i) {
				for(int j = 0; j < a.cols(); ++j) {
					c.matrix[i * c.rows() + j] = a.matrix[i * a.rows() + j] + b.matrix[i * b.rows() + j];
				}
			}
		}

		Matrix operator - (const Matrix &b) {
			
			return subtract(*this, b);
		}


};
#endif
