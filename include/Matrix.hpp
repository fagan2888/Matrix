#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
#include<stdexcept>
#include<iostream>
#include<cblas.h>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include<boost/smart_ptr/make_shared_array.hpp>

namespace GPUMatrix {

    template<typename T>class Matrix{

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
                    matrix = boost::make_shared<T[]>(nrows * ncols);
                } catch (std::exception &e) {
                    throw;
                }
            };

            void allocate(T default_val) {
#ifdef DBG
                std::cout << "Allocating array" << std::endl;
#endif
                try {
                    matrix = boost::make_shared<T[]>(nrows * ncols, default_val);
                } catch (std::exception &e) {
                    throw;
                }
            };   

            void deallocate() {
#ifdef DBG
                std::cout << "Deallocating array" << std::endl;
#endif
            };

            const T Get(const int row_, const int col_) const{
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return matrix[row_ * ncols + col_];
            };

            T &Set(const int row_, const int col_) {	
                if(row_ < 0 || col_ < 0)
                    throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
                if (row_ >= nrows || col_ >= ncols)
                    throw std::invalid_argument(std::string("Element out of bounds"));
                return *(matrix.get() + row_ * ncols + col_);
            };


        public:
            explicit Matrix() : nrows(1), ncols(1), matrix(boost::make_shared<T[]>(1 * 1, 0.0)) {
#ifdef DBG
                std::cout << "Constructing Matrix" << std::endl;
#endif	
                try{
                    allocate(); 
                } catch (std::exception &e) {
                    throw;
                }
            };

            explicit Matrix(const int nrows_, const int ncols_, const T default_val = 0.0) : nrows(nrows_), ncols(ncols_), matrix(boost::make_shared<T[]>(nrows_ * ncols_, default_val)){
#ifdef DBG
                std::cout << "Constructing Matrix" << std::endl;
#endif	
                try {
                    allocate(default_val);
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
                for(int i = 0; i < this->rows(); ++i) {
                    for(int j = 0; j < this->cols(); ++j) {
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

            const Matrix operator * (const Matrix &b) const{	
                return multiply(*this, b);
            }

            const Matrix operator + (const Matrix &b) const{	
                return add(*this, b);
            }

            const Matrix operator - (const Matrix &b) const{
                return subtract(*this, b);
            }

            const T *get_pointer() const{
                return matrix.get();
            }
            const Matrix multiply(const Matrix &a, const Matrix &b) const{
#ifdef DBG
                std::cout << "Multiplying Matrix" << std::endl;
#endif
                if(a.cols() != b.rows())
                    throw std::invalid_argument(std::string("Matrix dimensions are not compatible for multiplication"));
                Matrix c(a.rows(), b.cols(), 0.0);

                cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, a.rows(), b.cols(), a.cols(), 1.0, const_cast<T*>(a.get_pointer()), a.cols(), const_cast<T*>(b.get_pointer()), b.cols(), 0.0, const_cast<T*>(c.get_pointer()), c.cols()); 

                return c;
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

            void print() const{
                for (int i = 0; i < nrows; ++i) {
                    for(int j = 0; j < ncols; ++j)
                        std::cout << this->Get(i, j) << " ";
                    std::cout << "\n";
                }
                std::cout << "\n";
            }


            friend std::ostream& operator << (std::ostream& os, const Matrix<T> &b) {
                for(int i = 0; i < b.cols(); ++i) {
                    for(int j = 0; j < b.rows(); ++j) {
                        os << b(i, j) << " ";
                    }
                    os << "\n";
                }
                os << "\n";
                return os;
            };

    };
        	  
}
#endif
