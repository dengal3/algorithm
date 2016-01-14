#include <iostream>
#include <set>
using namespace std;

int a1, a2, a3, a4, b1, b2, c;
int f[100005];
set<int> x_set;
int n;
bool first_equal = false;

int cal_h(int num) {
		return a1*f[num-2]*f[num-1] + a2*f[num-2]+a3*f[num-1]+a4;
} 

int cal_f(int num) {
	int h = cal_h(num);
	//cout << h << endl;
	if (h > b1) {
			while(h > b2) {
					h -= c;
			}
	}
	return h;
}

bool find() {
		int x = cal_f(n);
		//cout << x << endl;
		if (x_set.find(x) != x_set.end() && first_equal) {
				for (int i = 1; i < n; i++) {
						if (f[i] == x) {
								cout << i-1 << " " << n-i;
								return true;
						}
				}
		} else if (x_set.find(x) != x_set.end()){
				first_equal = true;
		} else {
				first_equal = false;
				x_set.insert(x);
		}
		f[n++] = x;
		return false;
}

int main() {
		cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> c;
		int x1, x2;
		cin >> x1 >> x2;
		x_set.insert(x1);
		x_set.insert(x2);
		f[1] = x1;
		f[2] = x2;
		n = 3; // start from 3
		//cout << "gg" << endl;
		while(!find());
}