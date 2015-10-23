#include <iostream>
#include <string>
using namespace std;

int main() {
		string n;
		cin >> n;
		int add_n = 0;
		for (int i = 0; i < n.length(); i++) {
			add_n += n[i] - '0';
		}
		if (add_n % 3 == 0) {
				cout << "2" << endl;
		} else {
				cout << "1" << endl;
				cout << add_n%3 << endl;
		}
}