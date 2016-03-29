#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
#include<stdexcept>
#include<iostream>
#include<cblas.h>
#include<boost/smart_ptr/allocate_shared_array.hpp>
#include<boost/smart_ptr/make_shared_array.hpp>

namespace GPUMatrix 
{
    template<typename T>class Matrix
    {
        public:
            Matrix();
            Matrix(const int nrows, const int ncols, const T default_val =0.0);
            Matrix(const Matrix& b);
            ~Matrix();
            const std::string name() const;
            const int rows() const;
            const int cols() const;
            const std::pair<int, int> dims() const;
            const Matrix& operator = (const Matrix& b);
            const T operator () (const int row, const int col) const;
            const Matrix operator * (const Matrix& b) const;
            const Matrix operator + (const Matrix& b) const;
            const Matrix operator - (const Matrix& b) const;
            T& operator () (const int row, const int col);
            void print() const;      

        private:
            boost::shared_ptr<T[]> m_matrix;
            int m_nrows;
            int m_ncols;
            const std::string m_type = "Matrix";		
            void allocate(); 
            void allocate(T default_val);   
            void deallocate(); 
            const T Get(const int row, const int col) const; 
            T& Set(const int row, const int col);
            const T* get_pointer() const;
            const Matrix multiply(const Matrix& a, const Matrix& b) const;
            const Matrix add(const Matrix& a, const Matrix& b) const;  
            const Matrix subtract(const Matrix& a, const Matrix& b) const;

            //friend std::ostream & operator <<(std::ostream &os, const Matrix<T> &b);
    };

    template<> const GPUMatrix::Matrix<double> GPUMatrix::Matrix<double>::multiply(const GPUMatrix::Matrix<double> &a, const GPUMatrix::Matrix<double> &b) const 
    {
#ifdef DBG
        std::cout << "Multiplying Matrix" << std::endl;
#endif
        if(a.cols() != b.rows())
            throw std::invalid_argument(std::string("Matrix dimensions are not compatible for multiplication"));

        GPUMatrix::Matrix<double> c(a.rows(), b.cols(), 0.0);

        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, a.rows(), b.cols(), a.cols(), 1.0, const_cast<double*>(a.get_pointer()), a.cols(), const_cast<double*>(b.get_pointer()), b.cols(), 0.0, const_cast<double*>(c.get_pointer()), c.cols()); 

        return a;
    }
};
#endif
