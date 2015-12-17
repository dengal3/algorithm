#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int cal(int n) {
		int res = 0;
		char buffer[50];
		sprintf(buffer, "%d", n);
		for (int i = 0; i < strlen(buffer); i++) {
				int digit = buffer[i]-'0';
				if (digit> 4) digit--;
				res = res*9 + digit;
		}
		return res;
}

int main() {
		int n;
		while (cin >> n && n) {
			cout << n << ": " << cal(n) << endl;
		}
}