#include <iostream>
#include "stdio.h"
#include <cmath>
using namespace std;

int power[13];
double fac[13];
int t;

double find(double left, double right, int endM, double result) {
		if (right - left < 1e-6) {
				return right;
		}
		double middle = (right + left)/2;
		double sum = 0;
		for (int i = 0; i < t; i ++) {
				sum += fac[i]*pow(1+middle, endM-power[i]+1);
		}
		if (sum == result) {
				return middle;
		} else if (sum > result) {
				return find(left, middle, endM, result);
		} else {
				return find(middle, right, endM, result);
		}
}

int main() {
		int count = 0;
		while(cin >> t && t != -1) {
				int endM;
				double result;
				
				for (int i = 0 ; i < t; i++) {
						cin >> power[i] >> fac[i];
				}
				cin >> endM >> result;
				
				double r = find(0, 1, endM, result);
				
				count++;
				if (count > 1) {
					cout << endl;
				}
				printf("Case %d: %.5f\n", count, r);
		}
}