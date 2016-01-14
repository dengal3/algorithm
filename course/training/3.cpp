#include <iostream>
using namespace std;

struct Town {
		int x;
		int y;
		Town(int _x, int _y) {
				x = _x;
				y = _y;
		}
}
Town towns[10005];
bool visited[10005]
void getPath() {
		
}

int main() {
		int n;
		cin >> n;
		for (int i = 0; i  < n; i++) {
			int x, y;
			cin >> x >> y;
			visited[i] = false;
			towns[i] = Town(x, y);
		}
		getPath(0);
}