#include <iostream>
#include <string.h>
#include <queue>
#include <map>
using namespace std;
#define MAX 10005
bool composite[MAX];

void fast_gen_prime(int n) {
		for (int i = 2; i <= n; i++) {
				if(composite[i]) continue;
				for (int j = i*i; j <= n; j+=i)
					composite[j] = true;
		}
}

int find_pre(int n) {
		int sum = 0;
		int count = 0;
		queue<int> nums;
		map<int, int> mark;	// mark the state
		for (int i = 2; i <= n; i++) {
				if (!composite[i]) {
						sum += i;
						nums.push(i);
				}
				while (sum > n) {
						sum -= nums.front();
						nums.pop();
				}
				if (sum == n) {
					if (!mark.count(nums.front())) {
						count++;
						mark.insert(pair<int, int>(nums.front(), nums.back()));
					}
				}
		}
		return count;
}

int main() {
		memset(composite, 0, sizeof(composite));
		fast_gen_prime(MAX);
		int n;
		while (cin >> n && n) {
				cout << find_pre(n) << endl;
		}
}