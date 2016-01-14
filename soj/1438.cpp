#include <iostream>
#include <algorithm>
using namespace std;

bool sort_func(int a, int b) {
		return a > b;
}

int main() {
		int t;
		cin >> t;
		while (t--) {
				int n;
				int items[20005];
				cin >> n;
				for (int i = 0; i < n; i++) {
						cin >> items[i];
				}
				sort(items, items+n, sort_func);
				int discount = 0;
				for (int i = 0; i < n; i++) {
						if (i%3 == 2) {
								discount += items[i];
						}
				}
				cout << discount << endl;
		}
}