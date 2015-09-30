#include <iostream>
#include <stack>
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

int pick(int cards[], int *max, int *begin, int *end, int countA, int countB, int finishedState[][1005]) {
		if (*begin >= *end) {
			if (*begin == *end) {
				countA += cards[*begin];
			}
			*max = countA-countB > *max ? countA-countB : *max;
			return *max;
		} else {
			if (finishedState[*begin][*end]) {
				int nextToEnd = finishedState[*begin][*end];
				//restate(record_do, &countB, cards, begin, end);
				//countA -= cards[*begin];
				//(*begin)--;
				*max =  countA-countB+nextToEnd > *max ?  countA-countB+nextToEnd : *max;
				return *max;
			}
			
			int record_do;  // 0-left 1-right
			countA += cards[*begin];  // pick the left card
			(*begin)++; 
			countB += greedyPick(cards, *begin, *end, &record_do);
			if (record_do == 0) {
					(*begin)++;
			} else {
					(*end)--;
			}
			finishedState[*begin][*end] = pick(cards, max, begin, end, countA, countB, finishedState);
			cout << "finishedState at " << *begin << '\t' << *end << " : " <<  finishedState[*begin][*end] << endl;
			// restate
		//	if (record_do == 0) {
		//			(*begin)--;
		//			countB -= cards[*begin];
		//	} else {
		//			(*end)++;
		//			countB -= cards[*end];
		//	}
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
			//if (finishedState[*begin][*end]) {
				//int nextToEnd = finishedState[*begin][*end];
				//restate(record_do, &countB, cards, begin, end);
				//countA -= cards[*end];
				//(*end)++;
				//*max =  countA-countB+nextToEnd > *max ?  countA-countB+nextToEnd : *max;
				//return *max;
			//}
			finishedState[*begin][*end] = pick(cards, max, begin, end, countA, countB, finishedState);
			cout << "finishedState at " << *begin << '\t' << *end << " : " <<  finishedState[*begin][*end] << endl;
			
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
				int finishedState[1005][1005] = {0};
				int max = 0;
				int begin, end;  // the cards head and tail
				
				for (int i = 0; i < n; i++) {
						cin >> cards[i];
				}
				
				begin = 0;
				end = n-1;
				pick(cards, &max, &begin, &end, 0, 0, finishedState);
				
				cout << "In game " << t << "," << "the greedy strategy might lose by as many as "
				<< max << " points." << endl;
				
				cin >> n;
				t++;
		}
		return 0;
}