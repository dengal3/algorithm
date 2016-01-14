/*
	倒蛇阵填数
	author: dengailin
*/

#include <iostream>
using namespace std;

int main() {
		int circle_num = 1;  // set the first circle
		int input_num = 1;	// the num put into the matrix
		int n; 	//side
		int **matrix;
		
		cin >> n;
		
		matrix = new int*[n];
		
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
		}
		while (circle_num < n+1-circle_num) {
				for (int i = circle_num; i <= n+1-circle_num; i++) {
						matrix[i-1][n+1-circle_num-1] = input_num;
						input_num++;
				}
				for (int i = n-circle_num; i >= circle_num ; i--) {
						matrix[n+1-circle_num-1][i-1] = input_num;
						input_num++;
				} 
				for (int i = n-circle_num; i >= circle_num; i--) {
						matrix[i-1][circle_num-1] = input_num;
						input_num++;
				} 
				for (int i = circle_num+1; i <= n-circle_num; i++) {
						matrix[circle_num-1][i-1] = input_num;
						input_num++;
				} 
				circle_num++;
		}
		
		if (circle_num == n+1-circle_num) {
			matrix[circle_num-1][circle_num-1] = input_num;
		}
		
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
						cout << matrix[i][j] << '\t';
				}
				cout << endl;
		}
		
		return 0;
}