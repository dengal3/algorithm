#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int max_depth;
int width[105];	// record the width of each level
int level;	// state the current level
bool visited[105];
struct node {
	vector<int> next;
};
node *graph;
bool flag;	// if it is a forest

void dfs(int start) {
		visited[start] = true;
		if (graph[start].next.empty()) {
				if (level > max_depth) {
						max_depth = level;
				}
				return;
		}
		for (int i = 0 ; i < graph[start].next.size(); i++) {
				// if there are two edges pointing to the same node
				if (visited[graph[start].next[i]]) {
						flag = false;
						return;
				}
				level++;
				width[level]++;
				visited[graph[start].next[i]] = true;
				dfs(graph[start].next[i]) ;
				if (!flag) {
						return;
				}
				// go back
				level--;
		}
}

int main() {
		int n, m;
		while (cin >> n >> m && n != 0) {
				graph = new node[105];
				for (int i = 0 ;i < m; i++) {
						int s, e;
						cin >> s >> e;
						graph[s].next.push_back(e);
				}
				
				// find all roots
				vector<int> roots;
				roots.clear();
				bool mark[105] = {0};
				for (int i = 1; i <= n; i++) {
						for (int j = 0 ; j < graph[i].next.size(); j++) {
								mark[graph[i].next[j]] = true;
						}
				}
				for (int i = 1; i <= n; i++) {
					if (!mark[i]) {
							roots.push_back(i);
					}
				}
				// dfs all roots
				flag = true;
				max_depth = 0;
				memset(width, 0, sizeof(int)*105);
				memset(visited, 0, sizeof(bool)*105);
				width[0] = roots.size();
				for (int i = 0; i < roots.size(); i++) {
						level = 0;	// start from root
						dfs(roots[i]);
				}
				// if there is some loop
				for (int i = 1; i <= n; i++) {
						if (!visited[i]) {
								flag = false;
						}
				}

				if (!flag) {
						cout << "INVALID" << endl;
				} else {
						sort(width, width+max_depth+1);
						/*for (int i = 0; i <= max_depth; i++) {
								cout << width[i] << '\t';
						}
						cout << endl;*/
						cout << max_depth << " " << width[max_depth] << endl;
				}
		}
}