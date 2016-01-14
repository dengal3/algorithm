#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

set<string> state_set;
vector<string> ans;
const string End = "000000000";
struct Press {
		string res;	// the result state
		string nums;	// press which num before
		Press() {};
		Press(string _res, const char * _nums): res(_res), nums(_nums) {};
		Press(string _res, string _nums): res(_res), nums(_nums) {};
};
queue<Press> q;

string inverso(string s, int pos) {
		int dirs[8][2] =  {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
		pos--;	// start from 0
		int x = pos/3, y = pos%3;
		for (int i = 0 ; i < 8; i++) {
				if (x+dirs[i][0] >= 0 && x+dirs[i][0] < 3 && y+dirs[i][1] >= 0 && y+dirs[i][1] < 3) {
						int nx = x+dirs[i][0], ny = y+dirs[i][1];	// neighbor
						s[nx*3+ny] ^= 1;
				}
		}
		s[pos] ^= 1;
		return s;
}

bool cmp(const string &a, const string &b) {
		return a.length() < b.length()  || (a < b);
}

void bfs(string init) {
	state_set.insert(init);
	q.push(Press(init, ""));
	if (init == End) {
			cout << "11" << endl;
			return;
	}
	while (!q.empty()) {
			Press node = q.front();	q.pop();
			string cur = node.res;
			string nums = node.nums;
			for (int i = 1; i <= 9; i++) {
				if (nums.find(char(i+'0')) != string::npos) continue;
				string nxt = inverso(cur, i);
				if (state_set.count(nxt) > 0) continue; 
				nums.push_back(i+'0');
				if (nxt == End) {
						ans.push_back(nums);	// insert the answer
						continue;
				}
				state_set.insert(nxt);
				q.push(Press(nxt, nums));
				nums.erase(nums.length()-1);
			}
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans[0] << endl;
}

int main() {
		int n;
		cin >> n;
		while (n--) {
			string init;
			ans.clear();
			state_set.clear();
			for (int i = 0 ; i < 9; i++) {
					char ch;
					cin >> ch;
					if (ch == 'b') {
							init.push_back('1');
					} else {
							init.push_back('0');
					}
			}
			bfs(init);
		}
}