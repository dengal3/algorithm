#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_func(string a, string b) {
		return a + b < b + a;
}


int main() {
		int t;
		cin >> t;
		
		while (t--) {
				int n;
				string sub[8];
				vector<string> sub_vec;
				string result;
				cin >> n;
				
				for (int i = 0; i < n; i++) {
					string subStr;
					cin >> subStr;
					sub_vec.push_back(subStr);
				}
				
				sort(sub_vec.begin(), sub_vec.end(), cmp_func);
				
				result = "";
				for (int i = 0; i < n; i++) {
						result = result + sub_vec.front();
						sub_vec.erase(sub_vec.begin());
				}
				cout << result << endl;
		}
}