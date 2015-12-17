#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


typedef vector<int> State;
State *map;
long count;
int n, l;
int edge[110][110];

void go(int s, int e, int l) {
		if (!l) {
				if (s == e)
					count++;
					return;
		}
		//cout << s << '\t'<< e << '\t' << map[s].size() << endl;
		//cout << count << endl;
		for (int i = 0; i < map[s].size(); i++) {
				--l;
				go(map[s][i], e, l);
				++l;
		}
}

long long getPlan(int s, int e, int l) {
		if (l == 1) {
			for (int i = 0 ; i < map[s].size(); i++)
				if (map[s][i] == e) {
					return 1;
				}
			return 0;
		}
		long long plans = 0;
		for (int i = 1 ; i <= n; i++) {
					plans += getPlan(s, i, l-1) * getPlan(i, e, 1);
		}
		return plans;
}
 long ans[110][100][110];
 long cal() {
	int i, j, k;
	memset(ans, 0, sizeof(ans));
	for (i = 1 ; i<= l; i++) {
		for (int s = 1; s <= n; s++) {
			ans[0][s][s] = 1;
			for (j = 1; j <= n; j++) {
					for (k = 1; k <= n; k++) {
							ans[i][s][j] += ans[i-1][s][k] * edge[k][j];
					}
			}
		}
	}
}

int main() {
		int m;
		cin >> n >> m >> l;
		map = new State[n+1];	//start from 1
		memset(edge, 0, sizeof(edge));
		for (int i = 0 ; i < m; i++) {
				int s, e;
				cin >> s >> e;
				//map[s].push_back(e);
				edge[s][e]++;
		}
		int q;
		cin >> q;
		cal();
		while (q--) {
				int s, e;
				cin >> s >> e;
				//count = 0;
				//go(s, e, l);
				//cout << getPlan(s, e, l) << endl;
				cout << ans[l][s][e] << endl;
		}
}