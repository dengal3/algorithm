/**
 * 	big integer mod
 **/
#include <iostream>
#include <string.h>
using namespace std;

int charToInt(char num_ch) {
	return num_ch-'0';
}

int main() {
	int t, n;
	cin >> t;

	while(t--) {
			cin >> n;
			int b[120];  // store the basic
			char big_int[420] ;
			int len;
			int k[120];
			
			for (int i = 0; i < n; i++) {
				cin >> b[i];
			}
			
			cin >> big_int;
			len = strlen(big_int);
			
			for (int i = 0; i < n; i++) {
				int ten_mod[420];
				// build the ten_mod array
				ten_mod[0] = 1;
				for (int j= 1; j < 420; j++) {
					ten_mod[j] = (ten_mod[j-1]*10) % b[i];
				}
				
				k[i] = 0;
				for (int j = len-1; j >= 0; j--) {
						k[i] = (k[i]+charToInt(big_int[j])*ten_mod[len-1-j]) % b[i];
				}
			}
			
			cout << '(' << k[0] << ',';
			for (int i = 1; i < n-1; i++) {
				cout << k[i] << ',';
			}
			cout << k[n-1] << ')' << endl;
	}
	return 0;
}