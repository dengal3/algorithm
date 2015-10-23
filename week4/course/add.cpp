#include <iostream>
#include <string>
using namespace std;

string clear(string a) {
		if(a == "") {
			return "0";	
		}
		while (a.length() > 0 && a[0] == '0') {
				a.erase(0, 1);
		}
		if (a == "") {
				return "0";
		}
		return a;
}

bool bigger(string a, string b)  {
	if (a.length() > b.length()) {
			return true;
	}
	if (a.length () == b.length() && a >= b) {
			return true;
	}
	return false;
}

string addition(string a, string b) {
		int i;
		while (a.length() < b.length()) {
				a = "0" + a;
		}
		while (a.length() > b.length()) {
				b = "0" + b;
		}
		a = "0" + a;
		b = "0" + b;
		for (int i = a.length()-1; i > 0; i--) {
				a[i] = a[i] + b[i] - '0';
				if (a[i] > '9') {
						a[i] -= 10;
						a[i-1] += 1;
				}
		}
		return clear(a);
}

int main() {
		string a, b;
		cin >> a >> b;
		cout << addition(a, b) << endl;
}