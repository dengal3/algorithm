#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector< vector<int> > graph;

set<int> find_root() {
	set<int> roots;	// store the roots
	set<int> hasIn;
	for (int i = 1; i <= graph.size(); i++) {
			for (int j = 0; j < graph[i].size(); j++) {
					if (!hasIn.count(graph[i][j])) {
							hasIn.insert(graph[i][j]);
					}
			}
	}
	for (int i = 1; i <= graph.size(); i++) {
			if (!hasIn.count(i)) {
					roots.insert(i);
			}
	}
	return roots;
}

bool trace() {
		set<int> roots = find_root();
		for (set<int>::iterator it = roots.begin(); it != roots.end(); it++) {
				cout << *it << endl;
		}
}

int main() {
		int n, m;
		while (cin >> n >> m && n) {
			// build graph
			for (int i = 1; i <= n; i++) {
					vector<int> hold;
					graph.push_back(hold);
			}
			for (int i = 0; i < m; i++) {
					int s, e;
					cin >> s >> e;
					graph[s].push_back(e);
			}
			trace();
		}
}