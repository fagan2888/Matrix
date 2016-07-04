#ifndef __INSTypeRUMENType__
#define __INSTypeRUMENType__

#include<string>
#include<exception>
#include<stdexcept>
#include<iostream>
#include<cblas.h>
#include<memory>

namespace GPUMatrix 
{
    template<typename Type, typename IndexType = int>class Matrix
    {
        public:
            Matrix();
            Matrix(const IndexType nrows, const IndexType ncols, const Type default_val =0.0);
            Matrix(const Matrix& b);
            ~Matrix();
            const std::string name() const;
            const IndexType rows() const;
            const IndexType cols() const;
            const std::pair<IndexType, IndexType> dims() const;
            const Matrix& operator = (const Matrix& b);
            const Type operator () (const IndexType row, const IndexType col) const;
            const Matrix operator * (const Matrix& b) const;
            const Matrix operator + (const Matrix& b) const;
            const Matrix operator - (const Matrix& b) const;
            Type& operator () (const IndexType row, const IndexType col);
            void print() const;      

        private:
            std::unique_ptr<Type[]> m_matrix;
            IndexType m_nrows;
            IndexType m_ncols;
            const std::string m_type = "Matrix";		
            void allocate(); 
            void allocate(Type default_val);   
            void deallocate(); 
            const Type Get(const IndexType row, const IndexType col) const; 
            Type& Set(const IndexType row, const IndexType col);
            const Type* get_pointer() const;
            const Matrix multiply(const Matrix& a, const Matrix& b) const;
            const Matrix add(const Matrix& a, const Matrix& b) const;  
            const Matrix subtract(const Matrix& a, const Matrix& b) const;

            //friend std::ostream & operator <<(std::ostream &os, const Matrix<Type> &b);
    };

    template<> const GPUMatrix::Matrix<double> GPUMatrix::Matrix<double>::multiply(const GPUMatrix::Matrix<double> &a, const GPUMatrix::Matrix<double> &b) const 
    {
#ifdef DEBUG
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
