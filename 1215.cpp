#include <iostream>
#include <cstring>
using namespace std;

enum Direction {North = 0, South = 1, West = 2, East = 3};

int n, m;
char map[25][25];
int h[160005];
int p[160005];
bool visited[420][420];
int tot;
int step[160005];
bool rock[25][25];
bool magma[25][25];
Direction hmove[4];

int encode(int x, int y) {return x*m+y;};
int toX(int pos) {return pos/m; };
int toY(int pos) { return pos%m; };
int* toNext(int x, int y, Direction d) {	// mark
		int *res = new int[2];
		switch (d) {
				case North:
					res[0] = x-1;
					res[1] = y;
					break;
				case South:
					res[0] = x+1;
					res[1] = y;
					break;
				case West:
					res[0] = x;
					res[1] = y-1;
					break;
				case East:
					res[0] = x;
					res[1] = y+1;
					break;
				default:
					break;
		}
		return res;
}

void bfs(int cur) {
		int px = toX(p[cur]), py = toY(p[cur]);
		int hx = toX(h[cur]), hy = toY(h[cur]);
		
		if (cur > tot || step[cur] >= 255) {
				cout << "Impossible" << endl;
				return;
		}
		
		// Focus on Paris
		for (int i = 0 ; i < 4; i++) {
				Direction pD = Direction(i);
				Direction pH = hmove[i];
				int nxtPx = toNext(px, py, pD)[0], nxtPy = toNext(px, py, pD)[1];
				int nxtHx = toNext(hx, hy, pH)[0], nxtHy = toNext(hx, hy, pH)[1];
				
				if (rock[nxtHx][nxtHy]) {	// if rock, helen doen'tmove
						 nxtHx = hx;
						 nxtHy = hy;
				}
				if (!visited[encode(nxtPx, nxtPy)][encode(nxtHx, nxtHy)]) {
					if (!rock[nxtPx][nxtPy] && !magma[nxtPx][nxtPy] && !magma[nxtHx][nxtHy]) {
							if ((nxtPx == nxtHx && nxtPy == nxtHy) || ((nxtPx == hx) &&(nxtPy == hy) && (nxtHx == px) && (nxtHy == py)) ) {	// meet!
									cout << step[cur]+1 << endl;
									return;
							}
							tot++;
							p[tot] = encode(nxtPx, nxtPy);
							h[tot] = encode(nxtHx, nxtHy);
							step[tot] = step[cur]+1;
							visited[p[tot]][h[tot]] = true;
					}
				}
		}
		bfs(cur+1);
}

int main() {
		memset(rock, 0, sizeof(rock));
		memset(magma, 0, sizeof(magma));
		memset(step, 0, sizeof(rock)); // mark
		memset(visited, 0, sizeof(visited));
		cin >> n;
		cin >> m;
		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < m; j++) {
					cin >> map[i][j];
					switch (map[i][j]) {
							case 'H': {
								h[0] = encode(i, j);
								break;
							}
							case 'P': {
								p[0] = encode(i, j);
								break;
							}
							case '#': {
								rock[i][j] = 1;
								break;
							}
							case '!' : {
								magma[i][j] = 1;
								break;
							}
							default: {
								break;
							}
					}
			}
		}
		for (int i = 0 ; i < 4; i++) {
				char ch;
				cin >> ch;
				switch(ch) {
						case 'N':
							hmove[i] = North;
							break;
						case 'S':
							hmove[i] = South;
							break;
						case 'E':
							hmove[i] = East;
							break;
						case 'W':
							hmove[i] = West;
							break;
						default:
							break;
				}
		}
		visited[p[0]][h[0]] = true;
		step[0] = 0;
		tot = 0;
		bfs(0);
}