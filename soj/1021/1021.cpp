#include <iostream>
#include <stack>
using namespace std;

struct Couple {
		int c1;
		int c2;
		
		Couple(int a, int b) {
				c1 = a;
				c2 = b;
		}
};

bool checkCouple(int a, int b, int allcouple[], int n) {
		if (allcouple[a] == b || allcouple[b] == a) {
				return true;
		}
		else return false;
}
bool checkFinish(int coupleAmount, int n) {
		if (coupleAmount == n) {
				return true;
		}
		return false;
}

int nextCirclePoint(bool circle[], int circle_point, int n) {
	circle_point = circle_point+1 > 2*n? 1: circle_point+1;
	while(!circle[circle_point]) {
			circle_point = circle_point+1 > 2*n? 1: circle_point+1;
	}
	return circle_point;
}

int beforeCirclePoint(bool circle[], int circle_point, int n) {
	circle_point = circle_point-1 <= 0? 2*n: circle_point-1;
	while(!circle[circle_point]) {
			circle_point = circle_point-1 <= 0? 2*n: circle_point-1;
	}
	return circle_point;
}

int main() {
		int n; // n pairs couples
		cin >> n;
		while (n) {
				int allcouple[100005] = {0};  // store couple info
				//bool allcouple[100005][100005] = {false};  //store couple info
				bool circle[200010]; // store circle info
				stack<Couple> removed_couple_stack;
				int circle_point;  // point to the current position in circle
				bool first_run_flag = true;  // is the first time to get to the position 1
				
				for (int i = 0; i < n; i++) {
					int a, b;
					cin >> a >> b;
					allcouple[a] = b;
				}
				
				for (int i = 0; i <= 2*n; i++) {
						circle[i] = true;
				}
				
				circle_point = 1;
				circle[0] = false; // abandon the position 0
				while (true) {
						int nextPoint = nextCirclePoint(circle, circle_point, n);
						first_run_flag = false;
						//cout << "testing nextPoint" << '\t' << nextPoint <<  endl;
						if (checkCouple(circle_point, nextPoint, allcouple, n)) {
								//cout << "is couple" << endl;
								circle[circle_point] = circle[nextPoint] = false;  // pull couple out
								removed_couple_stack.push(*(new Couple(circle_point, nextPoint)));
								if (checkFinish(removed_couple_stack.size(), n)) {
										cout << "Yes" << endl;
										break;
								}
								//cout << "unfinshed" << endl;
								circle_point = 1;
								first_run_flag = true; // begin the new run
						} else {
								// get the next valid point
								circle_point = nextCirclePoint(circle, circle_point, n);
								if (beforeCirclePoint(circle, circle_point, n) > circle_point && !first_run_flag) {
										if (!removed_couple_stack.empty()) {
												circle_point = removed_couple_stack.top().c2;
												circle[removed_couple_stack.top().c1] = circle[circle_point] = true;  // put them back
												removed_couple_stack.pop();
												first_run_flag = true;
										} else {
											cout << "No" << endl;
											break;
										}
								}
						}
				}
				cin >> n;
		}
}