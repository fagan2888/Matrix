#include<Matrix.hpp>
#include<complex>

template<typename Type, typename IndexType> void GPUMatrix::Matrix<Type, IndexType>::allocate()
{
#ifdef DEBUG
    std::cout << "Allocating array" << std::endl;
#endif
    try 
    {
        m_matrix = std::make_unique<Type[]>(m_nrows * m_ncols);
    } catch (std::exception &e) 
    {
        throw;
    }
};

template<typename Type, typename IndexType> void GPUMatrix::Matrix<Type, IndexType>::allocate(Type default_val) 
{
#ifdef DEBUG
    std::cout << "Allocating array" << std::endl;
#endif
    try {
        m_matrix = std::make_unique<Type[]>(m_nrows * m_ncols);
    } catch (std::exception &e) {
        throw;
    }
};

template<typename Type, typename IndexType> void GPUMatrix::Matrix<Type, IndexType>::deallocate()
{
#ifdef DEBUG
    std::cout << "Deallocating array" << std::endl;
#endif
};

template<typename Type, typename IndexType> const Type GPUMatrix::Matrix<Type, IndexType>::Get(const IndexType row_, const IndexType col_) const
{
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return m_matrix[row_ * m_ncols + col_];
};

template<typename Type, typename IndexType> Type &GPUMatrix::Matrix<Type, IndexType>::Set(const IndexType row_, const IndexType col_) 
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return *(m_matrix.get() + row_ * m_ncols + col_);
            
};


template<typename Type, typename IndexType> GPUMatrix::Matrix<Type, IndexType>::Matrix() : m_nrows(1), m_ncols(1), m_matrix(std::make_unique<Type[]>(1 * 1)) 
{
#ifdef DEBUG
    std::cout << "Constructing Matrix" << std::endl;
#endif	
};

template<typename Type, typename IndexType> GPUMatrix::Matrix<Type, IndexType>::Matrix(const IndexType nrows_, const IndexType ncols_, const Type default_val//= 0. 0
        ) : m_nrows(nrows_), m_ncols(ncols_), m_matrix(std::make_unique<Type[]>(nrows_ * ncols_))
{
#ifdef DEBUG
    std::cout << "Constructing Matrix" << std::endl;
#endif	
};

template<typename Type, typename IndexType> GPUMatrix::Matrix<Type, IndexType>::Matrix(const Matrix<Type, IndexType> &b) 
{
#ifdef DEBUG
    std::cout << "Copy Constructor" << std::endl;
#endif
    this->m_nrows = b.rows();
    this->m_ncols = b.cols();
    try {
        this->allocate();
    } catch (std::exception &e) {
        throw;
    } 

    for(IndexType i = 0; i < this->m_nrows; ++i) {
        for(IndexType j = 0; j < this->m_ncols; ++j) {
            this->Set(i, j) = b(i, j);
        }
    }
}

template<typename Type, typename IndexType> GPUMatrix::Matrix<Type, IndexType>::~Matrix()
{
#ifdef DEBUG
                std::cout << "De-constructing Matrix" << std::endl;
#endif	
};

template<typename Type, typename IndexType> const std::string GPUMatrix::Matrix<Type, IndexType>::name() const 
{
    return m_type;
}

template<typename Type, typename IndexType> const IndexType GPUMatrix::Matrix<Type, IndexType>::rows() const
{
    return m_nrows;
};

template<typename Type, typename IndexType> const IndexType GPUMatrix::Matrix<Type, IndexType>::cols() const
{
    return m_ncols;
};

template<typename Type, typename IndexType> const std::pair<IndexType, IndexType> GPUMatrix::Matrix<Type, IndexType>::dims() const{
    return std::pair<IndexType, IndexType> (m_nrows, m_ncols);
}

template<typename Type, typename IndexType> const GPUMatrix::Matrix<Type, IndexType>& GPUMatrix::Matrix<Type, IndexType>::operator = (const GPUMatrix::Matrix<Type, IndexType> &b) 
{
#ifdef DEBUG
    std::cout << "= Operator" << std::endl;
#endif
    this->m_nrows = b.m_nrows;
    this->m_ncols = b.cols();
    this->m_matrix = std::make_unique<Type[]>(m_nrows * m_ncols);

    for(IndexType i = 0; i < this->rows(); ++i) {
        for(IndexType j = 0; j < this->cols(); ++j) {
            this->Set(i, j) = b(i, j);
        }
    }

    return *this;
}

template<typename Type, typename IndexType> const Type GPUMatrix::Matrix<Type, IndexType>::operator () (const IndexType row_, const IndexType col_) const
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return Get(row_, col_);
}

template<typename Type, typename IndexType> Type& GPUMatrix::Matrix<Type, IndexType>::operator () (const IndexType row_, const IndexType col_) 
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return Set(row_, col_);
}

template<typename Type, typename IndexType> const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::operator * (const GPUMatrix::Matrix<Type, IndexType> &b) const
{	
    return multiply(*this, b);
}

template<typename Type, typename IndexType>const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::operator + (const GPUMatrix::Matrix<Type, IndexType> &b) const
{	
    return add(*this, b);
}

template<typename Type, typename IndexType>const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::operator - (const GPUMatrix::Matrix<Type, IndexType> &b) const
{
    return subtract(*this, b);
}

template<typename Type, typename IndexType> const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::multiply(const GPUMatrix::Matrix<Type, IndexType> &a, const GPUMatrix::Matrix<Type, IndexType> &b) const 
{
#ifdef DEBUG
    std::cout << "Multiplying Matrix" << std::endl;
#endif
    std::cout << "Multiplication of type currently not supported" << std::endl;
}

template<typename Type, typename IndexType>const Type* GPUMatrix::Matrix<Type, IndexType>::get_pointer() const 
{
    return m_matrix.get();
}

template<typename Type, typename IndexType>const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::add(const GPUMatrix::Matrix<Type, IndexType> &a, const GPUMatrix::Matrix<Type, IndexType> &b) const
{
#ifdef DEBUG
    std::cout << "Adding Matrix" << std::endl;
#endif
    Matrix<Type, IndexType> c(a.rows(), a.cols());

    if((a.cols() != b.cols()) || (a.rows() != b.rows()))
        throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));

    for(IndexType i = 0; i < a.rows(); ++i) {
        for(IndexType j = 0; j < a.cols(); ++j) {
            c(i, j) = a(i, j) + b(i, j);
        }
    }
    return c;
}

template<typename Type, typename IndexType>const GPUMatrix::Matrix<Type, IndexType> GPUMatrix::Matrix<Type, IndexType>::subtract(const GPUMatrix::Matrix<Type, IndexType> &a, const GPUMatrix::Matrix<Type, IndexType> &b) const
{
#ifdef DEBUG
    std::cout << "Subtracting Matrix" << std::endl;
#endif
    if((a.cols() != b.cols()) || (a.rows() != b.rows())) 
        throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));

    GPUMatrix::Matrix<Type, IndexType> c(a.rows(), a.cols());

    for(IndexType i = 0; i < a.rows(); ++i) {
        for(IndexType j = 0; j < a.cols(); ++j) {
            c(i, j) = a(i, j) - b(i, j);
        }
    }
    return c;
}

template<typename Type, typename IndexType>void GPUMatrix::Matrix<Type, IndexType>::print() const
{
    for (IndexType i = 0; i < m_nrows; ++i) {
        for(IndexType j = 0; j < m_ncols; ++j)
            std::cout << this->Get(i, j) << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

template class GPUMatrix::Matrix<double>;

/*template<typename Type, typename IndexType>std::ostream& GPUMatrix::Matrix<Type, IndexType>::operator << (std::ostream& os, const GPUMatrix::Matrix<Type, IndexType> &b) 
{
    for(IndexType i = 0; i < b.cols(); ++i) {
        for(IndexType j = 0; j < b.rows(); ++j) {
            os << b(i, j) << " ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}*/
