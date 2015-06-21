#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
#include<stdexcept>
#include<cblas.h>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include<boost/smart_ptr/make_shared_array.hpp>

namespace GPUMatrix {

	template<class T>class Matrix{

        public:
            explicit Matrix(){
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

            explicit Matrix(const int nrows_, const int ncols_){
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
            };

            const std::string name() const {
                return type;
            }
            const int rows() const{
                return nrows;
            };

            const int cols() const{
                return ncols;
            };

            const Matrix& operator = (const Matrix &b) {
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

            const T operator () (const int row_, const int col_) const{	
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return Get(row_, col_);
            }

            T &operator () (const int row_, const int col_) {	
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return Set(row_, col_);
            }

            const Matrix multiply(const Matrix &a, const Matrix &b) const{
#ifdef DBG
                std::cout << "Multiplying Matrix" << std::endl;
#endif
                if(a.cols() != b.rows())
                    throw std::invalid_argument(std::string("Matrix dimensions are not compatible for multiplication"));
                Matrix c(a.rows(), b.cols());

                return c;
            }

            const Matrix operator * (const Matrix &b) const{	
                return multiply(*this, b);
            }

            const Matrix add(const Matrix &a, const Matrix &b) const{
#ifdef DBG
                std::cout << "Adding Matrix" << std::endl;
#endif
                Matrix c(a.rows(), a.cols());

                if((a.cols() != b.cols()) || (a.rows() != b.rows()))
                    throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));

                for(int i = 0; i < a.rows(); ++i) {
                    for(int j = 0; j < a.cols(); ++j) {
                        c(i, j) = a(i, j) + b(i, j);
                    }
                }
                return c;
            }

            const Matrix operator + (const Matrix &b) const{	
                return add(*this, b);
            }

            const Matrix subtract(const Matrix &a, const Matrix &b) const{
#ifdef DBG
                std::cout << "Subtracting Matrix" << std::endl;
#endif
                if((a.cols() != b.cols()) || (a.rows() != b.rows())) 
                    throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));

                Matrix c(a.rows(), a.cols());

                for(int i = 0; i < a.rows(); ++i) {
                    for(int j = 0; j < a.cols(); ++j) {
                        c(i, j) = a(i, j) - b(i, j);
                    }
                }
                return c;
            }

            const Matrix operator - (const Matrix &b) const{
                return subtract(*this, b);
            }

            void print() const{
                for (int i = 0; i < nrows; ++i) {
                    for(int j = 0; j < ncols; ++j)
                        std::cout << this->Get(i, j) << " ";
                    std::cout << "\n";
                }
                std::cout << "\n";
            }

        private:
            boost::shared_ptr<T[]> matrix;
            int nrows;
            int ncols;
            const std::string type = "Matrix";		
            void allocate() {
#ifdef DBG
                std::cout << "Allocating array" << std::endl;
#endif
                try {
                    matrix = boost::make_shared<T[]>(nrows * ncols, 0.0);
                } catch (std::exception &e) {
                    throw;
                }
            };
            void deallocate() {
#ifdef DBG
                std::cout << "Deallocating array" << std::endl;
#endif
            };

            T &Set(const int row_, const int col_) {	
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return *(matrix.get() + row_ * ncols + col_);
            };

            const T Get(const int row_, const int col_) const{
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return matrix[row_ * ncols + col_];
            };



	};

	template<class T>std::ostream& operator<<(std::ostream& os, const Matrix<T> &b) {
		    for(int i = 0; i < b.rows(); ++i) {
			    for(int j = 0; j < b.cols(); ++j) {
				    os << b(i, j) << " ";
		    }
		    os << "\n";
		}
		os << "\n";
        return os;
    };

}
#endif
