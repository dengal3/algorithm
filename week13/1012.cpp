#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include "stdio.h"
#include <algorithm>
using namespace std;

typedef complex<double> Point;
typedef Point Vector;
#define X real()
#define Y imag()

Point cal(Point a, Point b) {
		Vector ab = b - a;
		Point mid = ab/Point(2, 0) + a;
		Vector ab_vert = ab * Point(0, 1);
		return sqrt(4 - abs(mid - a)*abs(mid-a))*(ab_vert/Point(abs(ab_vert)))+mid;
}

bool sort_fun(Point a, Point b) {
		return a.X < b.X;
}

int main() {
	int n;
	while (cin >> n && n) {
			vector<Point> circles;
			for (int i = 0 ; i< n; i++) {
					double x;
					cin >> x;
					circles.push_back(Point(x, 1));
			}
			sort(circles.begin(), circles.end(), sort_fun);
			for (int i = n-1; i >= 1; i--) {
				int count = i;
				while(count--) {
					Point cur = circles.at(0);
					circles.erase(circles.begin());
					Point newP = cal(cur, circles.at(0));
					circles.push_back(newP);
				}
				circles.erase(circles.begin());
			}
			printf("%.4f %.4f\n", circles[0].X, circles[0].Y);
	}
}