#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
		int nProb;
		cin >> nProb;
		for (int i = 1; i <= nProb; i++) {
				int n;
				double circles[11];
				cin >> n;
				for (int j = 0; j < n; j++) {
						cin >> circles[j];
				}
				sort(circles, circles+n);
				double y = 0;
				for (int j = 0; j < n-1; j++) {
						double dis = (circles[j+1]-circles[j])/2;
						y += sqrt(4-dis*dis);
				}
				cout << i << ": " << fixed << setprecision(4) << (circles[n-1]+circles[0])/2
							<< " " << fixed << setprecision(4) << y+1 << endl;
		}
		return 0;
}