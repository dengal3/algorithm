#include <iostream>
#include <algorithm>
using namespace std;

int main() {
		int n;
		while (cin >> n && n) {
				int *stus = new int[n];
				int *handout = new int[n];
				int *temp = new int[n];
				for (int i = 0; i < n; i++) {
						cin >> stus[i];
						temp[i] = stus[i];
				}
				sort(temp, temp+n);
				int count = 0;
				while (temp[0] != temp[n-1]) {
						count++;
						for (int i = 0 ; i < n; i++) {
								handout[i] = stus[i]/2;
								stus[i] /= 2;
						}
						for (int i = 0 ; i < n; i++) {
								int before = i-1 >= 0? i-1: n-1;
								stus[i] += handout[before];
								if (stus[i] % 2) {
										stus[i]++;
								}
								temp[i] = stus[i];
						}
						sort(temp, temp+n);
				}
				cout << count << " " << temp[0] << endl;
		}
}