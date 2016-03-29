#include<Matrix.hpp>
#include<complex>

template<typename T> void GPUMatrix::Matrix<T>::allocate()
{
#ifdef DBG
    std::cout << "Allocating array" << std::endl;
#endif
    try 
    {
        m_matrix = boost::make_shared<T[]>(m_nrows * m_ncols);
    } catch (std::exception &e) 
    {
        throw;
    }
};

template<typename T> void GPUMatrix::Matrix<T>::allocate(T default_val) 
{
#ifdef DBG
    std::cout << "Allocating array" << std::endl;
#endif
    try {
        m_matrix = boost::make_shared<T[]>(m_nrows * m_ncols, default_val);
    } catch (std::exception &e) {
        throw;
    }
};

template<typename T> void GPUMatrix::Matrix<T>::deallocate()
{
#ifdef DBG
    std::cout << "Deallocating array" << std::endl;
#endif
};

template<typename T> const T GPUMatrix::Matrix<T>::Get(const int row_, const int col_) const
{
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return m_matrix[row_ * m_ncols + col_];
};

template<typename T> T &GPUMatrix::Matrix<T>::Set(const int row_, const int col_) 
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return *(m_matrix.get() + row_ * m_ncols + col_);
            
};


template<typename T> GPUMatrix::Matrix<T>::Matrix() : m_nrows(1), m_ncols(1), m_matrix(boost::make_shared<T[]>(1 * 1, 0.0)) 
{
#ifdef DBG
    std::cout << "Constructing Matrix" << std::endl;
#endif	
};

template<typename T> GPUMatrix::Matrix<T>::Matrix(const int nrows_, const int ncols_, const T default_val//= 0. 0
        ) : m_nrows(nrows_), m_ncols(ncols_), m_matrix(boost::make_shared<T[]>(nrows_ * ncols_, default_val))
{
#ifdef DBG
    std::cout << "Constructing Matrix" << std::endl;
#endif	
};

template<typename T> GPUMatrix::Matrix<T>::Matrix(const Matrix<T> &b) 
{
#ifdef DBG
    std::cout << "Copy Constructor" << std::endl;
#endif
    this->m_nrows = b.rows();
    this->m_ncols = b.cols();
    try {
        this->allocate();
    } catch (std::exception &e) {
        throw;
    } 

    for(int i = 0; i < this->m_nrows; ++i) {
        for(int j = 0; j < this->m_ncols; ++j) {
            this->Set(i, j) = b(i, j);
        }
    }
}

template<typename T> GPUMatrix::Matrix<T>::~Matrix()
{
#ifdef DBG
                std::cout << "De-constructing Matrix" << std::endl;
#endif	
};

template<typename T> const std::string GPUMatrix::Matrix<T>::name() const 
{
    return m_type;
}

template<typename T> const int GPUMatrix::Matrix<T>::rows() const
{
    return m_nrows;
};

template<typename T> const int GPUMatrix::Matrix<T>::cols() const
{
    return m_ncols;
};

template<typename T> const std::pair<int, int> GPUMatrix::Matrix<T>::dims() const{
    return std::pair<int, int> (m_nrows, m_ncols);
}

template<typename T> const GPUMatrix::Matrix<T>& GPUMatrix::Matrix<T>::operator = (const GPUMatrix::Matrix<T> &b) 
{
#ifdef DBG
    std::cout << "= Operator" << std::endl;
#endif
    this->m_nrows = b.rows();
    this->m_ncols = b.cols();
    this->m_matrix = boost::make_shared<T[]>(m_nrows * m_ncols);

    for(int i = 0; i < this->rows(); ++i) {
        for(int j = 0; j < this->cols(); ++j) {
            this->Set(i, j) = b(i, j);
        }
    }

    return *this;
}

template<typename T> const T GPUMatrix::Matrix<T>::operator () (const int row_, const int col_) const
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return Get(row_, col_);
}

template<typename T> T& GPUMatrix::Matrix<T>::operator () (const int row_, const int col_) 
{	
    if(row_ < 0 || col_ < 0)
        throw std::invalid_argument(std::string("Elements cannot be less than 0"));	
    if (row_ >= m_nrows || col_ >= m_ncols)
        throw std::invalid_argument(std::string("Element out of bounds"));
    return Set(row_, col_);
}

template<typename T> const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::operator * (const GPUMatrix::Matrix<T> &b) const
{	
    return multiply(*this, b);
}

template<typename T>const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::operator + (const GPUMatrix::Matrix<T> &b) const
{	
    return add(*this, b);
}

template<typename T>const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::operator - (const GPUMatrix::Matrix<T> &b) const
{
    return subtract(*this, b);
}

template<typename T> const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::multiply(const GPUMatrix::Matrix<T> &a, const GPUMatrix::Matrix<T> &b) const 
{
#ifdef DBG
    std::cout << "Multiplying Matrix" << std::endl;
#endif
    std::cout << "Multiplication of type currently not supported" << std::endl;
}

template<typename T>const T* GPUMatrix::Matrix<T>::get_pointer() const 
{
    return m_matrix.get();
}

template<typename T>const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::add(const GPUMatrix::Matrix<T> &a, const GPUMatrix::Matrix<T> &b) const
{
#ifdef DBG
    std::cout << "Adding Matrix" << std::endl;
#endif
    Matrix<T> c(a.rows(), a.cols());

    if((a.cols() != b.cols()) || (a.rows() != b.rows()))
        throw std::invalid_argument(std::string("Matrix dimensions are not compatible for addition"));

    for(int i = 0; i < a.rows(); ++i) {
        for(int j = 0; j < a.cols(); ++j) {
            c(i, j) = a(i, j) + b(i, j);
        }
    }
    return c;
}

template<typename T>const GPUMatrix::Matrix<T> GPUMatrix::Matrix<T>::subtract(const GPUMatrix::Matrix<T> &a, const GPUMatrix::Matrix<T> &b) const
{
#ifdef DBG
    std::cout << "Subtracting Matrix" << std::endl;
#endif
    if((a.cols() != b.cols()) || (a.rows() != b.rows())) 
        throw std::invalid_argument(std::string("Matrix dimensions are not compatible for subtraction"));

    GPUMatrix::Matrix<T> c(a.rows(), a.cols());

    for(int i = 0; i < a.rows(); ++i) {
        for(int j = 0; j < a.cols(); ++j) {
            c(i, j) = a(i, j) - b(i, j);
        }
    }
    return c;
}

template<typename T>void GPUMatrix::Matrix<T>::print() const
{
    for (int i = 0; i < m_nrows; ++i) {
        for(int j = 0; j < m_ncols; ++j)
            std::cout << this->Get(i, j) << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

template class GPUMatrix::Matrix<double>;

/*template<typename T>std::ostream& GPUMatrix::Matrix<T>::operator << (std::ostream& os, const GPUMatrix::Matrix<T> &b) 
{
    for(int i = 0; i < b.cols(); ++i) {
        for(int j = 0; j < b.rows(); ++j) {
            os << b(i, j) << " ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}*/
