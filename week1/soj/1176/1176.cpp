#include <iostream>
#include <cmath>
using	 namespace std;
const int INFINITE = 1000000;
int cards[1005];
int arrivedState[1005][1005];

int greedyPick(int cards[], int left, int right, int *record_do) {
		if (cards[left] >= cards[right]) {
				*record_do = 0;
				return cards[left];
		} else {
				*record_do = 1;
				return  cards[right];
		}
}

int pick(int begin, int end) {
		if (begin == end) {
				arrivedState[begin][end] = cards[begin];
				return arrivedState[begin][end];
		}
		if (begin +1== end) {
				return abs(cards[begin]-cards[end]);
		} else if (arrivedState[begin][end] != INFINITE) {
			return arrivedState[begin][end];
		} else {
				int aCard, bCard, record_do, left, right;
				// A pick the left card
				aCard = cards[begin];
				bCard = greedyPick(cards, begin+1, end, &record_do);
				if (record_do == 0) {
					left = aCard-bCard+pick(begin+2, end);
				} else {
					left = aCard-bCard+pick(begin+1, end-1);
				}
				// A pick the right card
				aCard = cards[end];
				bCard = greedyPick(cards, begin, end-1, &record_do);
				if (record_do == 0) {
					right = aCard-bCard+pick(begin+1, end-1);
				} else {
					right = aCard-bCard+pick(begin, end-2);
				}
				arrivedState[begin][end] = left>right? left: right;
		}
		return arrivedState[begin][end];
}

int main () {
		int n;
		int t = 1;
		cin >> n;
		while (n) {
				for (int i = 0; i < n; i++) {
						cin >> cards[i];
				}
				
				for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
								arrivedState[i][j] = INFINITE;
						}
				}
				
				cout << "In game " << t << ", " << "the greedy strategy might lose by as many as "
				<< pick(0, n-1) << " points." << endl;
				
				cin >> n;
				t++;
		}
		return 0;
}