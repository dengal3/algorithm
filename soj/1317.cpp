#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stdio.h>
using namespace std;
#define EMPTY 0
#define NUM 9

struct Pos {
		int x;
		int y;
		int val;
		Pos(int _x, int _y, int _val) {
				x = _x;
				y = _y;
				val = _val;
		}
};
struct State {
		vector<Pos> pos;
		State() {}
};

int sudo[NUM][NUM];	// store the sudo input state
set<int> empty;	// store the empty seats
queue<State> q;	// store the states
int count = 0;
int result[NUM][NUM];

vector<int> getAvailables(int x, int y, State cur) {
		vector<int> ret;
		vector<Pos> pos_vec = cur.pos;
		set<int> used;
		for (int i = 0; i < NUM; i++) {
				if (sudo[x][i] != EMPTY) {
						used.insert(sudo[x][i]);
				}
				if (sudo[i][y] != EMPTY) {
						used.insert(sudo[i][y]);
				}
		}
		for (int i = 0 ; i < pos_vec.size(); i++) {
				Pos temp = pos_vec[i];
				if (temp.x == x || temp.y == y) {
						used.insert(temp.val);
				}
		}
		int cursorX = x/3*3;
		int cursorY = y/3*3;
		for (int i = 0 ; i < NUM/3; i++) {
            for (int j = 0; j < NUM/3; j++) {
                int px = cursorX+i;
                int py = cursorY+j;
                if (sudo[px][py] != EMPTY) {
                    used.insert(sudo[px][py]);
                }
                for (int k = 0 ;k < pos_vec.size();k++) {
                    Pos temp = pos_vec[k];
                    if (temp.x == px && temp.y == py) {
                            used.insert(temp.val);
                    }
                }
            }
        }
		for (int i = 1; i <= NUM; i++) {
			if (!used.count(i)) {
					ret.push_back(i);
			}
		}
		return ret;
}

int getNext(State  cur) {
		vector<Pos> pos = cur.pos;
		set<int> ret = empty;
		for (int i = 0; i < pos.size(); i++) {
				if (ret.count(pos[i].x*NUM + pos[i].y)) {
						ret.erase(ret.find(pos[i].x*NUM + pos[i].y));
				}
		}
		return ret.empty() ? -1 : *ret.begin();
}

void record(State cur) {
    vector<Pos> res_vec = cur.pos;
    for (int i = 0 ; i < NUM; i++) {
        for (int j = 0 ; j < NUM; j++) {
            result[i][j] = EMPTY;
            if (sudo[i][j] != EMPTY) {
                result[i][j] = sudo[i][j];
            }
        }
    }
    for (int i = 0 ; i < res_vec.size(); i++) {
        Pos p = res_vec[i];
        result[p.x][p.y] = p.val;
    }
}

bool flag = true;
void bfs() {
		State temp;
		int x, y;
		if (!q.empty()) {
			temp = q.front();
		} else {
				if (!flag) return;
				flag = false;
		}
		int next = getNext(temp);
		if (next == -1) {
				count++;
                record(temp);
                if (!q.empty()) {
                    q.pop();
                }
				bfs();
				return;
		}

		if (!q.empty()) {
            q.pop();
        }

		x= next/NUM;
		y = next%NUM;
		vector<int> availables = getAvailables(x, y, temp);
		for (int j = 0; j < availables.size(); j++) {
				State newS;
				newS.pos = temp.pos;
				//cout << x << " " << y << " " << availables[j] << endl;
				newS.pos.push_back(Pos(x, y, availables[j]));
				q.push(newS);
		}
		bfs();
}

void print() {
    for (int i = 0 ; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}

int main() {
		int t;
		cin >> t;
		for (int i = 0 ; i < t; i++) {
				// clear sudo and input
				flag = true;
				while (!q.empty()) q.pop();
				empty.clear();
				count = 0;
				for (int j = 0 ; j < NUM; j++) {
						for (int k = 0 ; k < NUM; k++) {
								char num;
								sudo[j][k] = EMPTY;
								cin >> num;
								if (num != '_') {
										sudo[j][k] = num-'0';	// to num
										//cout << sudo[j][k];
								} else {
										//cout << j << " " << k << " " << j*9+k <<  '\t';
										empty.insert(j*NUM+k);	// store the empty seat
										//cout << empty.front() << endl;
								}
						}
				}
				bfs();	// breath first search
				if (count > 1) {
                    printf("Puzzle %d has %d solutions\n\n", i+1, count);
				} else if (count == 1){
                    printf("Puzzle %d solution is\n", i+1);
                    print();
				} else {
                    printf("Puzzle %d has no solution\n\n", i+1, count);
				}
		}
}
