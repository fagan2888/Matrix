#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>
#include<exception>
template<class T>class Matrix{
	

	private:
		T *matrix;
		int nrows;
		int ncols;
		std::string type = "Matrix";		
		void allocate();
		void deallocate();
		
	public:
		Matrix();
		Matrix(int nrows_, int ncols_);
		~Matrix();
		static Matrix multiply(const Matrix &a, const Matrix &b);
		static Matrix add(const Matrix &a, const Matrix &b);
		T &Set(int row, int col);
		T Get(int row, int col);
		int rows() const;
		int cols() const;
		Matrix operator * (const Matrix &b);
		Matrix operator + (const Matrix &b);
};

#endif
