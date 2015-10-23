#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Road;
struct Node {
		queue<Road> next;
		Node (){}
};
struct Road {
		int id;
		int end;
		int dis;
		Road(int i, int e, int d) {
				id = i;
				end = e;
				dis = d;
		}
};

vector<Road> tree[10005];
//Node *tree = new Node[10005]();
int max_dis = 0;
bool visited[10005];

void walk(int root, int dis) {
		for (int i = 0; i < tree[root].size(); i++) {
				if (!visited[tree[root][i].id]) {
						dis += tree[root][i].dis;
						visited[tree[root][i].id] = true;
						if (dis > max_dis) {
								max_dis = dis;
						}
						walk(tree[root][i].end, dis);
						
						// goback
						dis -= tree[root][i].dis;
						visited[tree[root][i].id] = false;
				}
		}
}

int main() {
		int n, k;
		int s, e, d;
		while( cin >> n >> k) {
			for (int i = 0; i <= n; i++) {
					tree[i].clear();
					visited[i]= false;
			}
			for (int i = 0; i < n-1; i++) {
					cin >> s >> e >> d;
					tree[s].push_back(*(new Road(i, e, d)));
					tree[e].push_back(*(new Road(i, s, d)));
			}
			max_dis = 0;
			walk(k, 0);  // start from the kth city
			cout << max_dis << endl;
		}
}