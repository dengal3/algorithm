#include <iostream>
#include <vector>
using namespace std;

class Edge {
	private:
		double x1;
		double y1;
		double x2;
		double y2;
public:
		Edge(double _x1, double _y1, double _x2, double _y2) {
				if (_x1 < _x2) {
					this->x1 = _x1;
					this->y1 = _y1;
					this->x2 = _x2;
					this->y2 = _y2;
				} else {
					this->x1 = _x2;
					this->y1 = _y2;
					this->x2 = _x1;
					this->y2 = _y1;
				}
		}
		static bool check(Edge& a, Edge &b) {
			double adj[2][3];
			bool done[2] = {0};
			int col = 3;
			int line = 2;
			adj[0][0] = a.x1-a.x2;
			adj[0][1] = b.x2-b.x1;
			adj[0][2] = b.x2-a.x2;
			adj[1][0] = a.y1-a.y2;
			adj[1][1] = b.y2-b.y1;
			adj[1][2] = b.y2-a.y2;
			bool flag = false;
			
			for (int i= 0; i < col-1; i++) {
					double max = -9999;
					int mark = -1;
					for (int j = 0 ; j < line; j++) {
							if (!done[j] && max < adj[j][i]) {
									max = adj[j][i];
									mark = j;
									done[mark] = true;
							}
					}
					//cout << "max: " << max << endl;
					//cout << "mark: " << mark << endl;
					if (max == 0) {
							flag = true;
							break;
					}
					for (int j = 0; j < line; j++) {
							if (j != mark) {
									//cout << adj[j][i] << '\t';
									double handle = -1*(adj[j][i]/max);
									//cout << "handle: " << handle;
									for (int k = 0; k < col; k++) {
											adj[j][k] += adj[mark][k]*handle;
									}
							}
					}

			}
			//cout <<"check: " <<   flag << endl;
			if (flag) {
					if ((a.x1 <= b.x1 && b.x1 <= a.x2) || (b.x1 <= a.x1 && a.x1 <= b.x2)) {
							return false;
					}
					return true;
			}
			return true;
		}
};
vector<Edge> map;


int main() {
		int t;
		while (cin >> t && t) {
				map.clear();
				int count = 0;
				for (int i = 0; i < t; i++) {
						double x1, y1, x2, y2;
						cin >> x1 >> y1 >> x2 >> y2;
						Edge newP = *(new Edge(x1, y1, x2, y2));
						bool flag = true;
						for (int j = 0; j < map.size(); j++) {
								if (!Edge::check(newP, map[j])) {
									flag = false;
									break;
								}
						}
						if (flag) {
								map.push_back(newP);
								count++;
						}
				}
				cout << count << endl;
		}
}