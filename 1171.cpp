#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int m, n;
bool map[20][20];
bool mask[20][20];

int res;

int countNbr(int x, int y) {
	int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	int count = 0;
	
	for (int i = 0 ; i < 8; i++) {
			int nx = (x + m + dirs[i][0])%m;
			int ny = (y+ n +dirs[i][1])%n;
			if (mask[nx][ny]) {
				count++;
			}
	}
	return count;
}
int zushu = 0;
bool isMatch() {
		bool next[20][20];
		memset(next, 0, sizeof(next));
		for (int i = 0; i < m; i++) {
				for (int j = 0 ; j < n; j++) {
						int nbrs = countNbr(i, j);
						if (!mask[i][j]) {
								if (nbrs == 3) {
										next[i][j] = true;	// born
								}
						} else {
								if (nbrs <= 1 || nbrs >= 4) {
										next[i][j] = false;	// die
								} else {
										next[i][j] = true;
								}
						}
						if (next[i][j] != map[i][j]) {
								return false;
						}
				}
		}
		return true;
}


void game(int cur) {
		if (cur == n*m) {
				if (isMatch()) {
					res++;
				}
				return;
		}
		for (int i = 0; i <= 1; i++) {
			mask[cur/n][cur%n] = i;
			game(cur+1);
		}
}

int main() {
		int t = 0;
		while (cin >> m >> n && m && n) {
				t++;
				memset(map, 0, sizeof(map));
				int k; cin >> k;
				while (k--){
					int x, y;
					cin >> x >> y;
					map[x][y] = true;
				}
				res = 0;
				game(0);
				if (res) {
						printf("Case %d: %d possible ancestors.\n", t, res);
				} else {
						printf("Case %d: Garden of Eden.\n", t);
				}
		}
		
}