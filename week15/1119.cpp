#include <iostream>
#include <cmath>

using namespace std;

int main() {
		int y;
		while (cin >> y && y) {
				double k = pow(2, (y-1960)/10+2);
				double sum = 0;
				int i = 0;
				while (sum < k) {
						i++;
						sum += log2(i);
				}
				i--;
				cout << i << endl;
		}
}