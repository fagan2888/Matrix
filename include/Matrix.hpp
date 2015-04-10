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
            try {
			    matrix = new T[nrows * ncols];
		    } catch (std::exception &e) {
                throw;
            }
        };
		void deallocate() {
#ifdef DBG
	std::cout << "Deallocating array" << std::endl;
#endif
            try {
			    delete[] matrix;
            } catch (std::exception &e) {
                throw;
            }
		};

		T &Set(int row, int col) {	
			if(row < 0 || col < 0)
				throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
			if (row >= nrows || col >= ncols)
				throw std::invalid_argument(std::string("Element out of bounds"));
			return *(matrix + row * ncols + col);
		};

		T Get(int row, int col) const{
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
            try{
			    allocate(); 
            } catch (std::exception &e) {
                throw;
            }
		};

		Matrix(int nrows_, int ncols_){
#ifdef DBG
			std::cout << "Constructing Matrix" << std::endl;
#endif	
			nrows = nrows_;
			ncols = ncols_;
			try {
                allocate();
            } catch (std::exception &e) {
                throw;
            } 
		};
		
		Matrix(const Matrix &b) {
#ifdef DBG
	std::cout << "Copy Constructor" << std::endl;
#endif
            try {
			    this->deallocate();
            } catch (std::exception &e) {
                throw;
            } 
            this->nrows = b.rows();
			this->ncols = b.cols();
			try {
                this->allocate();
            } catch (std::exception &e) {
                throw;
            } 
			
            for(int i = 0; i < this->nrows; ++i) {
				for(int j = 0; j < this->ncols; ++j) {
					this->Set(i, j) = b(i, j);
				}
			}
		}

		~Matrix(){
#ifdef DBG
			std::cout << "De-constructing Matrix" << std::endl;
#endif	
			deallocate();
		};

		std::string name() const {
			return type;
		}
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
		    try {
			    this->deallocate();
            } catch (std::exception &e) {
                throw;
            } 
            this->nrows = b.rows();
			this->ncols = b.cols();
			try {
                this->allocate();
            } catch (std::exception &e) {
                throw;
            } 	
            for(int i = 0; i < this->nrows; ++i) {
				for(int j = 0; j < this->ncols; ++j) {
					this->Set(i, j) = b(i, j);
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
					c(i, j) = a(i, j) + b(i, j);
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
					c(i, j) = a(i, j) - b(i, j);
				}
			}

			return c;
		}

		Matrix operator - (const Matrix &b) {
	        try{		
			    return subtract(*this, b);
            } catch (std::invalid_argument &ex) {
                throw ex;
            }
		}

		void print() const{
			for (int i = 0; i < nrows; ++i) {
				for(int j = 0; j < ncols; ++j)
					std::cout << this->Get(i, j) << " ";
				std::cout << "\n";
			}

            std::cout << "\n";
		}
};
#endif
