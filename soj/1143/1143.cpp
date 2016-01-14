#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "memory.h"
using	namespace std;

struct Paper{
		int pro;  //priority
		int ini_pos; // initial position
		Paper (int p, int i_pos) {
				pro = p;
				ini_pos = i_pos;
		}
};

bool comp_func(int a, int b) {return a<b;}

int main() {
		int t;
		cin >> t;
		while (t--) {
				int n, m;
				queue<Paper> q;
				vector<int> p;
				cin >> n >> m;
				p.clear();
				
				for (int i = 0;i < n; i++) {
						int pro;
						cin >> pro;
						p.push_back(pro);
						q.push(Paper(pro, i));
				}
				
				// sort the priority
				sort(p.begin(), p.end(), comp_func);
				

				int flag = false;
				int count = 1;
				while (!flag) {
						Paper current = q.front();
						if (current.pro >= p.back()) {
								if (current.ini_pos == m) {
										flag = true;
										break;
								} else {
										q.pop();
										p.pop_back();
										count++;
								}
						} else {
								q.pop();
								q.push(current);
						}
				}
				cout << count << endl;
		}
}