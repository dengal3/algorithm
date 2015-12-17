#include <iostream>
#include <queue>
#include "stdio.h"
using namespace std;

struct Player{
		queue<int> cards;
		int count;
		Player() {count = 1;}
};

int main() {
	int t;
	int count  = 0;
	cin >> t;
	while (t--) {
			count++;
			int n;	// n players
			cin >> n;
			Player *players = new Player[n];
			for (int i = 0; i < 52; i++) {
					int card;
					cin >> card;
					players[0].cards.push(card);	// first player has all cards at the beginning
			}
			int all = 0;
			for (int i = 0 ; i < n; i++) {
					all += players[i].cards.size();
			}
			
			bool flag = true;
			bool isfirst = true;
			queue<int> temp;
			int first;
			int markCount;
			
			int unchanged = 0;
			int discard = 0;

			while (discard != 52) {	// while not all empty
				// every round
					for (int i = 0 ; i < n; i++) {
							if (!players[i].cards.empty()) {
								
								int card = players[i].cards.front();
								if (players[i].count == card) {
										unchanged = -1;
										if (i < n-1) {
												players[i+1].cards.push(card);
										} else {
												discard++;
										}
								} else {
										players[i].cards.push(card);
								}
								players[i].cards.pop();
								players[i].count = (++players[i].count) > 13 ? 1 : players[i].count; 
						}
					}
					unchanged++;
					if (unchanged ==13*52) {
							flag = false;
							break;
					}
		}
	
		if (!flag) {
				printf("Case %d: unwinnable\n", count);
		} else {
				printf("Case %d:", count);
				for (int i = 0 ; i < n; i++) {
						printf(" %d", --players[i].count <= 0 ? 13: players[i].count);
				}
				printf("\n");
		}
	}
	return 0;
}