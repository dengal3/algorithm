#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1e+15
#define EPS 1e-7

int compare(double x1, double x2) {
		if (x1 - x2 < -EPS) {
				return -1;
		}
		if (x1 - x2 > EPS) {
				return 1;
		}
		return 0;
}

class Line {
private:
			double s;
			double e;
			double k;
			double b;
public:
		Line(double sx, double sy, double ex, double ey) {
				if (compare(ex, sx) == 0) {
						k = INF;
						b = sx;
						s = sy;
						e = ey;
				} else {
						k = (ey-sy) / (ex-sx);
						b = sy - k*sx;
						s = sx;
						e = ex;
				}
		}
		Line(const Line& l) {
				k = l.k;
				b = l.b;
				s = l.s;
				e = l.e;
		}
		double getStart() const{
				return s;
		}
		double getEnd() const {
				return e;
		}
		double getK() const {
				return k;
		}
		double getB() const {
				return b;
		}
};

bool cmp_func(Line a, Line b) {
		if (compare(a.getK(), b.getK()) == 0) {
				if (compare(a.getB(), b.getB() == 0)) {
						return compare(a.getStart(), b.getStart()) < 0;
				}
				return compare(a.getB(), b.getB()) < 0;
		}
		return compare(a.getK(), b.getK()) < 0;
}

int main() {
	int t;
	cin >> t;
	while(t != 0) {
			vector<Line> map;
			for (int i = 0 ; i < t; i++) {
					double x1, y1, x2, y2;
					cin >> x1 >> y1 >> x2 >> y2;
					if (compare(x1, x2) > 0) {
							swap(x1, x2);
							swap(y1, y2);
					} else if (compare(x1, x2) == 0) {
							if (compare(y1, y2) > 0) {
									swap(y1, y2);
							}
					}
					map.push_back(Line(x1, y1, x2, y2));
			}
			sort(map.begin(), map.end(), cmp_func);
			int num = map.size();
			double maxend = map.front().getEnd();
			vector<Line>::iterator it1, it2;
			for (it1 = map.begin(), it2= it1, ++it2; it2 != map.end(); it1++, it2++) {
					if (compare((*it1).getK(), (*it2).getK()) == 0 && compare((*it1).getB(), (*it2).getB()) == 0) {
							if ((*it2).getStart() <= maxend) {
									num--;
							}
							if (maxend < (*it2).getEnd()) {
								maxend = (*it2).getEnd();
							}
					} else {
							maxend = (*it2).getEnd();
					}
			}
			cout << num << endl;
			cin >> t;
	}
}