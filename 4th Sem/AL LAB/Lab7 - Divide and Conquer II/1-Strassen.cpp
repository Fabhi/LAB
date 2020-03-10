#include <iostream>
using namespace std;

void Multiply(int A[2][2], int B[2][2]){
		int p1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
		int p2 = (A[1][0] + A[1][1]) * B[0][0];
		int p3 = A[0][0] * (B[0][1] - B[1][1]);
		int p4 = A[1][1] * (B[1][0] - B[0][0]);
		int p5 = (A[0][0] + A[0][1]) * B[1][1];
		int p6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
		int p7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

		int c[2][2];
		c[0][0] = p1 + p4 - p5 + p7;
		c[0][1] = p3 + p5;
		c[1][0] = p2 + p4;
		c[1][1] = p1 - p2 + p3 + p6;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++)
				cout<<c[i][j]<<" ";
			cout<<endl;
		}
}


int main(){
	int A[2][2];
	int B[2][2];
	cout << "Enter the elements of Matrix A"<<endl;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++)
			cin >> A[i][j];
	}
	cout << "Enter the elements of Matrix B"<<endl;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++)
			cin >> B[i][j];
	}
	Multiply(A, B);
}