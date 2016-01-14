#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 9

char square[MAX+1][MAX+1];
bool row[MAX+1][MAX+1], col[MAX+1][MAX+1];
bool blo[MAX+1][MAX+1];
int num;
int ans[MAX+1][MAX+1];
int todo;
int block(int x, int y) { return (x-1)/3*3+(y-1)/3;};
struct Todo {
		int x, y, b, pNum;
		Todo() {};
		Todo(int _x, int _y): x(_x), y(_y), b(block(x, y)), pNum(0) {};
		void cal() {
				for (int i = 1; i <= MAX; i++) {
						if (!row[x][i] && !col[y][i] && !blo[b][i]) {
								pNum++;
						}
				}
		}
};

Todo p[MAX*MAX];
bool cmp(const Todo& a, const Todo& b) {return a.pNum < b.pNum;};

void dfs(int n) {
		if (n == todo) {
				num++;
				if (num == 1) {
						for (int i = 1 ; i <= MAX; i++) {
								for (int j = 1 ; j <= MAX; j++) {
										ans[i][j] = square[i][j] - '0';
								}
						}
				}
				return;
		}
		int x = p[n].x, y = p[n].y, b = block(x, y);
		for (int i = 1; i <= MAX; i++) {
				if (!row[x][i] && !col[y][i] && !blo[b][i]) {
						square[x][y] = i+'0';
						row[x][i] = 1;
						col[y][i] = 1;
						blo[b][i] = 1;
						
						dfs(n+1);
						
						row[x][i] = 0;
						col[y][i] = 0;
						blo[b][i] = 0;
				}
		}
}

int main() {
		int t, temp;
		cin >> t;
		temp = t;
		while (temp--) {
				if (t-temp != 1) {
						printf("\n");
				}
				todo = 0, num = 0;
				memset(row, 0, sizeof(row));
				memset(col, 0, sizeof(col));
				memset(blo, 0, sizeof(blo));
				memset(square, 0, sizeof(square));
				
				for (int i = 1 ; i <= MAX; i++) {
						for (int j = 1; j  <= MAX; j++) {
								char ch;
								cin >> ch;
								square[i][j] = ch;
								if (ch == '_') {
										p[todo] = Todo(i, j);
										todo++;
								} else {
										int tnum = square[i][j] - '0';
										row[i][tnum] = 1; 
										col[j][tnum] = 1; 
										blo[block(i, j)][tnum] = 1;
								}
						}
				}
				for (int i = 0; i < todo; i++)  {
					p[i].cal();
				}
				sort(p, p+todo, cmp); 
				dfs(0);
				
				if (num == 0) {
						printf("Puzzle %d has no solution\n", t-temp);
				} else if (num == 1) {
						printf("Puzzle %d solution is\n", t-temp);
						for (int i = 1 ; i <= MAX; i++) {
								for (int j=1; j <= MAX; j++) {
										cout << ans[i][j];
								}
								cout << endl;
						}
				} else {
						printf("Puzzle %d has %d solutions\n", t-temp, num);
				}
		}
}