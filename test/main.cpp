#include<iostream>
#include<Matrix.hpp>

using namespace std;

int main(int argc, char *argv[]) {

	Matrix *a = new Matrix[5];

	delete[] a;

	return 0;
}
