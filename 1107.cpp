#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string incpl[20];
vector<string*> res;
int sum;
int n, k;
int c;
bool inserted[20]; 		// 记录在dfs中已经插入的列
bool flag;
bool isSum() {
		int s = 0;
		for (int i = 0 ; i < n; i++) {
				s += atoi(incpl[i].c_str());
		}
		return s == sum;
}

bool isValid() {
		for (int i = 0 ; i <= k; i++) {
				set<char> col;
				for (int j = 0 ; j < n; j++) {
					if (col.count(incpl[j][i])) return false;
					
					col.insert(incpl[j][i]);
				}
		}
		return true;
}
void dfs(int cur_n) {		//利用cur_n枚举每一个不完整数字
		if (cur_n == n) {
				if(isValid() && isSum()) {
						flag = true;
						string *hold = new string[20];
						for (int i = 0 ; i < n; i++) {
								hold[i] = incpl[i];
						}
						res.push_back(hold);
				}
				return;
		}
		for (int i = 0; i <= k; i++) {		// 枚举位置
			if (!inserted[i]) {
				inserted[i] = true;
				for (int j = 1; j <= 9; j++) {		// 枚举插入的数字
						incpl[cur_n].insert(incpl[cur_n].begin()+i, j+'0');
						inserted[j] = true;
						
						dfs(cur_n+1);

						incpl[cur_n].erase(incpl[cur_n].begin()+i);
						inserted[j] =false;
				}
				inserted[i] = false;
			}
		}
}

bool isNum(char ch) { return ch>='0'  && ch<='9'; };
bool cmp(const string *a, const string *b) { return a[0] < b[0];};
int main() {
		while (cin >> c && c) {
				string temp;
				memset(inserted, 0, sizeof(inserted));
				n = 0;
				flag = false;
				res.clear();
				getline(cin, temp);
				while (temp.find(" ") != string::npos) {
						int pos = temp.find_first_of(" ");
						if (pos == 0) {
							temp.erase(0, pos+1);
							continue;
						}
						incpl[n++] = temp.substr(0, pos);
						temp.erase(0, pos+1);
				}
				k = incpl[n-1].length();
				sum = atoi(temp.c_str());
				dfs(0);
				if (!flag) {
					cout << c << " 0" << endl;
				} else {
						sort(res.begin(), res.end(), cmp);
						for (vector<string *>::iterator it = res.begin(); it != res.end(); it++) {
								cout << c;
								for (int i = 0; i < n; i++) {
										cout << " " << (*it)[i];
								}
								cout << endl;
						}
				}
		}
}