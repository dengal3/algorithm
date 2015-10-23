#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int greedyPick(int cards[], int left, int right, int *record_do) {
		if (cards[left] >= cards[right]) {
				*record_do = 0;
				return cards[left];
		} else {
				*record_do = 1;
				return  cards[right];
		}
}

void restate(int record_do, int *countB, int cards[], int *begin, int *end) {
	// restate
		if (record_do == 0) {
				(*begin)--;
				*countB -= cards[*begin];
		} else {
				(*end)++;
				*countB -= cards[*end];
		}
}

void pick(int cards[], int *max, int *begin, int *end, int countA, int countB, int arrivedState[][1005]) {
		if (*begin >= *end) {
			if (*begin == *end) {
				countA += cards[*begin];
			}
			*max = countA-countB > *max ? countA-countB : *max;
			return;
		} else {
			
			int record_do;  // 0-left 1-right
			countA += cards[*begin];  // pick the left card
			(*begin)++; 
			countB += greedyPick(cards, *begin, *end, &record_do);
			if (record_do == 0) {
					(*begin)++;
			} else {
					(*end)--;
			}
			pick(cards, max, begin, end, countA, countB, arrivedState);

			restate(record_do, &countB, cards, begin, end);
			(*begin)--;
			countA -= cards[*begin];
			
			// A pick the right first
			countA += cards[*end];  // pick the left card
			(*end)--; 
			countB += greedyPick(cards, *begin, *end, &record_do);
			if (record_do == 0) {
					(*begin)++;
			} else {
					(*end)--;
			}
			pick(cards, max, begin, end, countA, countB, arrivedState);
			
			restate(record_do, &countB, cards, begin, end);
			(*end)++;
			countA -= cards[*end];
			
		}
}

int main () {
		int n;
		int t = 1;
		cin >> n;
		while (n) {
				int cards[1005];
				int arrivedState[1005][1005] = {0};
				int max = 0;
				int begin, end;  // the cards head and tail
				
				for (int i = 0; i < n; i++) {
						cin >> cards[i];
				}
				
				begin = 0;
				end = n-1;
				pick(cards, &max, &begin, &end, 0, 0, arrivedState);
				
				cout << "In game " << t << "," << "the greedy strategy might lose by as many as "
				<< max << " points." << endl;
				
				cin >> n;
				t++;
		}
		return 0;
}