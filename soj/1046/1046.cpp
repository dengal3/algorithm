#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Period {
		int start; //start quarter
		int end; //end quarter
		double avg;
		
		Period(int s, int e, double a) {
				start =s;
				end = e;
				avg = a;
		}
};

int sumUp(int quarter[], int i, int j) {
		int sum = 0;
		for (int k = i; k <= j; k++) {
			sum += quarter[k];
		}
		return sum;
}

bool sort_func(Period a, Period b) {
		if (a.avg > b.avg) {
				return true;
		} else if (a.avg == b.avg) {
				if (a.end - a.start > b.end - b.start) {
						return true;
				} else if (a.end - a.start == b.end - b.start) {
						if (a.end < b.end) {
								return true;
						}
						return false;
				}
				return false;
		}
		return false;
}

int main() {
		int N;
		int run = 1;
		cin >> N;
		
		while (run <= N) {
				int n, length, min_quarter;
				int quarter[305];
				vector<Period> period_vec;
				cin >> n >> length >> min_quarter;
				
				for (int i = 0; i < n; i++) {
						cin >> quarter[i];
				}
				
				for (int i = 0; i < n-min_quarter+1; i++) {
						for (int j = i+min_quarter-1; j < n; j++) {
								int sum = sumUp(quarter, i, j);
								double avg = double(sum)/(j-i+1);
								period_vec.push_back(*new Period(i, j, avg));
						}
				}
				
				// sort the vector
				sort(period_vec.begin(), period_vec.end(), sort_func);
				
				cout << "Result for run " << run << ":" << endl;
				int output_length = period_vec.size()>= length? length : period_vec.size();
				int count = 0;
				for (vector<Period>::iterator it = period_vec.begin(); ;it++) {
						cout << it->start+1 << "-" << it->end+1 << endl;
						count++;
						if (count >= output_length) {
								break;
						}
				}
				
				run++;
		}
		return 0;
}