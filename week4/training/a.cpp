#include <iostream>
using namespace std;

int nums[10] = {0};

void add(int page) {
		while(page) {
				nums[page%10]++;
				page /= 10;
		}
}

int main() {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
				add(i);
		}
		for (int i = 0; i < 10; i++) {
				cout << nums[i] << endl;
		}
}