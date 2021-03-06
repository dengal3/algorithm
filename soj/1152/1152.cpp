#include <iostream>
#include <vector>
using namespace std;

bool visited[35];
int neighbors[10];
int op[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
vector<int> route;

bool isValid(int x, int y) {
		return x >= 0 && x < 6 && y >= 0 && y < 5;
}

bool walk(int start, int step) {
		//cout << step << ": " << start << endl;
		if (step >= 29) {
				for (int i = 1; i <= 30; i++) {
						if (!visited[i]) {
								return false;
						}
				}
				// print out the route
				for (int i = 0; i < route.size(); i++) {
						cout << route[i] << " ";
				}
				cout << endl;
				return true;
		}
		 for (int i = 0; i < 8; i++) {
				int x = (start-1)%6;
				int y = (start-1)/6;
				int next_x = x+op[i][0];
				int next_y = y+op[i][1];
				int next = next_y*6 + next_x + 1;
				if (isValid(next_x, next_y) && !visited[next]) {
						visited[next] = true;
						route.push_back(next);
						if (walk(next,++step)) {
								return true;
						}
						// goback
						route.pop_back();
						step--;
						visited[next] = false;
				}
		}
		return false;
}

int main() {
		int n;
		while (cin >> n && n != -1) {
			route.clear();
			for (int i = 0; i < 35; i++) {
				visited[i] = false;
			}
			route.push_back(n);
			visited[n] = true;
			walk(n, 0);  // x, y, step
		}
}