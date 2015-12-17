#include <iostream>
#include <complex>
#include <cmath>
#include "stdio.h"
using namespace std;

typedef complex<double> Point;
typedef Point Vector;
#define EPS 1e-8
#define INF 1e+7
#define X real()
#define Y imag()

Point getCross(Point a, Point b, Point c, Point d) {
	double k1, b1, k2, b2;
	double x, y;
	if (abs(a.X - b.X) > EPS) {
		k1 = (a.Y - b.Y) / (a.X - b.X);
		b1 = a.Y - k1*a.X;
	} else {
			k1 = INF;
			b1 = a.X;
	}
	
	if (abs(c.X - d.X) > EPS) {
		k2 = (c.Y - d.Y) / (c.X - d.X);
		b2 = c.Y - k2*c.X;
	} else {
			k2= INF;
			b2= c.X;
	}
	
	if (k1 == INF || k2 == INF) {
			if (k1 == INF) {
				x = b1;
				y = k2*x+b2;
			} else {
				x = b2;
				y = k1*x+b1;
			}
	} else {
		x = (b2 - b1) / (k1 - k2);
		 y = k1*x+b1;
	}
	return Point(x, y);
}



int main() {
		int t;
		cin >> t;
		while (t--) {
				double x1, x2, x3, y1, y2, y3;
				cin >> x1 >> y1
					>> x2 >> y2
					>> x3 >> y3;
				Point A = Point(x1, y1), B = Point(x2, y2), C = Point(x3, y3);
				Vector v1 = B - A;
				Vector v2 = C- A;
				Vector v3 = C - B;
				Vector v4 = A - B;
				v1 = v1 * Point(0, 1) + A;
				v2 = v2 * Point(0, -1) + A;
				v3 = v3 * Point(0, 1) + B;
				v4 = v4 * Point(0, -1) + B;
				//cout << v1 << '\t' << v2 << '\t' << v3 << '\t' << v4 << endl;
				Point m1 = (v1-v2) / Point(2, 0) + v2;
				Point m2 = (v3-v4) / Point(2, 0) + v4;
				//cout << m1 << '\t' << m2 << endl;
				Point cross = getCross(m1, A , m2, B);
				printf("%.4f %.4f\n", cross.X+EPS, cross.Y+EPS);
		}
}
