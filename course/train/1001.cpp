#include<iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
		int t;
		cin >> t;
		while (t--) {
				queue<string> p1;
				stack<string> p2;
				vector<string> p3;
				
				string action;
				while (cin >>action && action != "Read") {
						string word;
						if (action == "Take") {
								cin >> word;
								p1.push(word);
						} else if (action == "Push") {
							if (p1.empty()) continue;
								word = p1.front();
								p1.pop();
								p2.push(word);
						} else if (action == "Pop") {
							if (p2.empty()) continue;
								word = p2.top();
								p2.pop();
								p3.push_back(word);
						}
				}
				for (int i = p3.size()-1 ; i >= 0; i--) {
						cout << p3[i];
						if (i > 0) cout << " ";
				}
				cout << endl;
		}
		
}