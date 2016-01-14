#include <iostream>
#include <cmath>
using namespace std;

int gcd(long a, long b) {
		if (b == 0) {
				return a;
		}
		return gcd(b, a%b);
}

int lcm(long a, long b) {
		return (a*b)/gcd(a, b);
}

int main() {
		int t;
		cin >> t;
		while (t--) {
			long g, l;
			cin >> g >> l;
			int count = 0;
			for (int i = g; i <= l; i += g) {
				for (int j = i; j <= l; j+= g) {
					for (int k = j; k <= l; k += g) {
						int dup = 0;
						if ((k == i && k != j) || (i == j && i != k) || (k ==j && k != i)) dup = 1;
						if (k == i && k == j) dup = 2;
						if (gcd(gcd(i, j), k) == g && lcm(lcm(i, j), k) == l) {
							//cout << i << " " << j <<" " << k << endl;
								if (dup == 0) {
										count += 6;
								} else if (dup == 1) {
										count += 3;
								} else count +=1;
						}
					}
				}
			}
			cout << count << endl;
		}
}