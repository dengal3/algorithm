#include <iostream>
#include "stdio.h"

# define DOUBLE_INF 1.79e+308
#define INT_INF 2000000001
using namespace std;

int main() {
		int n;
		int flight[2][2];
		int t = 1;
		while (cin >> n && n) {
				cin >> flight[0][0] >> flight[0][1] >> flight[1][0] >> flight[1][1];
				int costA = flight[0][0], passA = flight[0][1], costB = flight[1][0], passB = flight[1][1];
				double a, b;
				//a = double(costA)/passA;
				//b = double(costB)/passB;
				
				if (passA == 0) {
					a = DOUBLE_INF;
				} else {
					a = double(costA)/passA;
				}
				if (passB == 0) {
					b = DOUBLE_INF;
				} else {
					b = double(costB)/passB;
				}
				 
				int better = b < a? 1: 0;
				int fCost = flight[better][0], fPass = (flight[better][1] > 0)? flight[better][1]: INT_INF,
					sCost = flight[(better+1) % 2][0], sPass= (flight[(better+1) % 2][1] > 0)? flight[(better+1)%2][1]: INT_INF;
				bool flag = false;
				for (int i = n/fPass; i >= 0; i--) {
						if ((n-i*fPass) % sPass == 0) {
								flag = true;
								if (better == 0) {
									printf("Data set %d: %d aircraft A, %d aircraft B\n", t, i, (n-i*fPass)/sPass);
								} else {
									printf("Data set %d: %d aircraft A, %d aircraft B\n", t,  (n-i*fPass)/sPass,i);
								}
								 break;
						}
				}
				if (!flag) {
						printf("Data set %d: cannot be flown\n", t);
				}
				t++;
		}
}