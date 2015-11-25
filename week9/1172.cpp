#include <iostream>
#include <set>
#include <vector>
#include "stdio.h"
using namespace std;
enum chessType {
	Empty, Knight, Queen, Pawn
};
struct Chess {
	chessType item;
	
	Chess() {
			item = Empty;	// empty
	}
	void put(chessType chess) {
			item = chess;
	}
};

Chess **board;
int n, m; // row and col
set< pair<int, int> > unsafeLocs;
vector< pair<int, int> > knightLocs;
vector< pair<int, int> > queenLocs;
vector< pair<int, int> > pawnLocs;

bool isValid(int x, int y) {
		return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool isEmpty(int x, int y) {
		return board[x][y].item == Empty;
}
int findUnsafe() {
		// find knight attack
		for (int i = 0; i < knightLocs.size(); i++) {
				int x = knightLocs[i].first;
				int y = knightLocs[i].second;
				int operations[8][2] = {{-2, -1}, {-1, -2}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}, {2, 1}, {1, 2}};
				for (int j = 0;j < 8; j++) {
						int newX = x+operations[j][0];
						int newY = y+operations[j][1];
						if (isValid(newX, newY) && isEmpty(newX, newY)) {
								if (!unsafeLocs.count(pair<int, int>(newX, newY))) {
										unsafeLocs.insert(pair<int, int>(newX, newY));
								}
						}
				}
		}
		// find Queen attack
		for (int i = 0; i < queenLocs.size(); i++) {
				int x = queenLocs[i].first;
				int y = queenLocs[i].second;
				int operations[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
				
				for (int j = 0; j < 8; j++) {
						int newX = x+operations[j][0];
						int newY = y+operations[j][1];
						while (isValid(newX, newY) && isEmpty(newX, newY)) {
								if (!unsafeLocs.count(pair<int, int>(newX, newY))) {
										unsafeLocs.insert(pair<int, int>(newX, newY));
								}
								newX += operations[j][0];
								newY += operations[j][1];
						}
				}
		}
}

int main() {
		int count = 1;
		while (cin >> n >> m && n && m) {
				unsafeLocs.clear();
				knightLocs.clear();
				queenLocs.clear();
				pawnLocs.clear();
				board = new Chess*[n+2];
				for (int i = 1; i < n+2; i++) {
						board[i] = new Chess[m+1];
				}
				// input
				int k, q, p;
				cin >> q;
				for (int i = 0; i < q; i++) {
						int x, y;
						cin >> x >> y;
						board[x][y].put(Queen);
						queenLocs.push_back(pair<int, int>(x, y));
				}
				cin >> k;
				for (int i = 0; i < k; i++) {
						int x, y;
						cin >> x >> y;
						board[x][y].put(Knight);
						knightLocs.push_back(pair<int, int>(x, y));
				}
				cin >> p;
				for (int i = 0; i < p; i++) {
						int x, y;
						cin >> x >> y;
						board[x][y].put(Pawn);
						pawnLocs.push_back(pair<int, int>(x, y));
				}
				// finished input
				
				//find all unsafe locations
				findUnsafe();

				printf("Board %d has %d safe squares.\n", count++, int(n*m-unsafeLocs.size())-q-k-p);
		}
}