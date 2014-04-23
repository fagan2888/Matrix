#ifndef __INSTRUMENT__
#define __INSTRUMENT__

#include<string>

class Matrix{


	private:
		double *matrix;
		int nrows;
		int ncols;
		std::string type = "Matrix";		
		void allocate();
		void deallocate();

	public:
		Matrix();
		Matrix(int nrows_, int ncols_);
		~Matrix();

};

#endif
