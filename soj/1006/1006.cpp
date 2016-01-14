#include <iostream>
#include <stack>
#include <set>
#include <cstring>
using namespace std;
const int LEN = 5;

bool place(int k, char test[]) {
		for (int i = 0; i < k; i++) {
				if (test[i] == test[k]) {
						return false;
				}
		}
		return true;
}

int check(char *test, char ranks[][8], int t) {
		set<string> a;
		for (int i = 0; i < LEN-1; i++) {
				for (int j = i+1; j < LEN; j++) {
						//cout << string(&test[i], 1) + string(&test[j], 1) << endl;
						a.insert(string(&test[i], 1) + string(&test[j], 1));
				}
		}
		
		int val = 0;
		for (int i = 0; i < t; i++) {
				int count = 0;
				for (int j = 0; j < LEN-1; j++) {
						for (int k = j+1; k < LEN; k++) {
							char temp1 = ranks[i][j],
								temp2 = ranks[i][k];
							//	cout << temp1 << '\t' << temp2 << endl;
							//cout << string(&ranks[i][j], 1) + string(&ranks[i][k], 1) << endl;
							if (a.find(string(&ranks[i][j], 1) + string(&ranks[i][k], 1)) == a.end()) {
								count++;
							}
						}
				}
				//cout << count << endl;
				val += count;
		}
		return val;
}



int main() {
		int t;
		while(cin >> t && t != 0) {
				char ranks[105][8];
				for (int i = 0; i < t; i++) {
					for (int j = 0; j < LEN; j++) {
						cin >> ranks[i][j];
					}
					ranks[i][LEN] = '\0';
				}
				
				char median[8];
				char test[8];
				test[0] = 'A';  // 1 turns to 'A'
				test[LEN] = '\0';
				int k = 0;
				int min = 9999999;
				while (k >= 0) {
						while (test[k] <= 'E' && !place(k, test)) {
								test[k]++;
						}
						if (test[k] <= 'E') {
								if (k == LEN-1) {
										int val = check(test, ranks, t);
										//cout << test << endl;
										if (val < min) {
												min = val;
												strcpy(median, test);
										}
										k--;
										if (k >= 0) {
											test[k]++;
											test[k+1] = 'A';
										}
								} else {
										k++;
										test[k] = 'A'; // set as 'A'
								}
						} else {
								k--;
								if (k >= 0) {
									test[k]++;
									test[k+1] = 'A';
								}
						}
				}
				cout << median << " is the median ranking with value " << min << "." << endl;
		}
}