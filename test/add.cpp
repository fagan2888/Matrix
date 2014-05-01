#include<iostream>
#include<Matrix.hpp>

using namespace std;

int main(int argc, char *argv[]) {

	Matrix b1(4, 1);
	Matrix b2(1, 4);
	Matrix b3(4, 4);

	double a1[4][1] = {{1.0}, {2.0}, {3.0}, {4.0}}; 
	double ans1[4][1];
	double a2[1][4] = {{1.0, 2.0, 3.0, 4.0}};
	double ans2[1][4];
	double a3[4][4] = {{1.0, 2.0, 3.0, 4.0}, {5.0, 6.0, 7.0, 8.0}, {9.0, 10.0, 11.0, 12.0}, {13.0, 14.0, 15.0, 16.0}};
	double ans3[4][4];

	cout<<"Beginning Addition Tests for following matrices" <<endl;


	cout << "Matrix 1 (4 x 1)" << endl;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 1; j++)
			cout << a1[i][j] << " ";
		cout << "\n";
	}

	cout << "Matrix 2 (1 x 4)" << endl;

	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 4; j++)
			cout << a2[i][j] << " ";
		cout << "\n";
	}

	cout << "Matrix 3 (4 x 4)" << endl;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++)
			cout << a3[i][j] << " ";
		cout << "\n";
	}

	try{
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 1; j++)
				cout << b1.Get(i, j) << endl;
		}
	}
	catch(exception &e){
		cout << e.what() << endl;
	
	}
	cout << "\n";

	try{
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 1; j++) {
				b1.Set(i, j) = static_cast<double>((i + 1) * 1 + j);
				cout << b1.Get(i, j) << endl;
			}
		}
	}
	catch(exception &e){
		cout << e.what() << endl;
	
	}
	return 0;
}
