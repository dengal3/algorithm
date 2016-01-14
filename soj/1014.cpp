#include <iostream>
using namespace std;

bool isMatch(int num) {
		int sum = 0;
		int base[3] = {10, 16, 12};
		
		for (int i = 0; i < 3; i++) {
				int temp = num;
				int holdSum = 0;
				while (temp) {
						holdSum += temp%base[i];
						temp /= base[i];
				}
				if (sum == 0) {
						sum = holdSum;
				} else if (sum != holdSum) {
						return false;
				}
		}
		return true;
}

int main() {
		for (int i = 2992; i < 10000; i++) {
				if (isMatch(i)) {
						cout << i << endl;
				}
		}
}