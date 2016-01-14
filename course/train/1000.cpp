#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool reverse_func(int a, int b) {
		return a >b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<int> odds;
		vector<int> evens;
		cin >>n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num %2 == 0) {
					evens.push_back(num);
			}else {
				odds.push_back(num);
			}
		}
		sort(odds.begin(), odds.end());
		sort(evens.begin(),evens.end(), reverse_func);
		
		for (int i = 0 ; i < odds.size(); i++)
			cout <<odds[i] << " ";
		
		for (int i = 0 ; i < evens.size()-1; i++)
			cout << evens[i] << " ";
		if (!evens.empty()) {
				cout << evens[evens.size()-1];
		}
		cout <<endl;
	}
}