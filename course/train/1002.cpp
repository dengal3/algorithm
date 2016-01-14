#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;

bool sort_fun(int a, int  b) {
		return a > b;
}

int main() {
		int n, m;
		while (cin >> n >>m) {
			if (!n && !m) break;
			if (n) {
				map<string, int> words;
				vector<int> sow;
				int temp = n;
				while (n--) {
						int t;
						cin >> t;
						for (int i = 0 ; i < t; i++) {
								string word;
								cin >> word;
								if (words.count(word)) {
									words.find(word)->second++;
								} else {
										words.insert(pair<string, int>(word, 1));
								}	
						}
				}
				for (map<string, int>::iterator it = words.begin(); it != words.end(); it++) {
						sow.push_back(it->second);
				}
				sort(sow.begin(), sow.end(), sort_fun);
				double sum = 0;
				for (int i = 0 ; i<min(m, int(sow.size())); i++) {
						sum += sow[i];
				}
				if (temp)
					printf("%.2f\n",sum/temp);
			} else {
				printf("%.2f\n", 0.0);
			}
		}
}