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
		void allocate() {
			matrix = new T[nrows * ncols];
		};
		void deallocate() {
			delete[] matrix;
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

		static Matrix multiply(const Matrix &a, const Matrix &b);
		static Matrix add(const Matrix &a, const Matrix &b);
		T &Set(int row, int col) {
			return *(matrix + row * ncols + col);
		};

		T Get(int row, int col) {
			if(row < 0 || col < 0)
				throw "Elements cannot be less than 0";
			return matrix[row * ncols + col];
		};

		int rows() const{
			return ncols;
		};
		
		int cols() const{
			return rows;
		};
		Matrix operator * (const Matrix &b);
		Matrix operator + (const Matrix &b);
};

#endif
