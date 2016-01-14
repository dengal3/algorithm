#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_func(pair<char, int> a, pair<char, int> b) {
		return a < b;
}

int main() {
		char keyword[15];
		while(cin >> keyword && strcmp(keyword, "THEEND")  != 0) {
			char secret[105], convert[100][100], result[100][100];
			int col_len, row_len;
			cin >> secret;
			
			col_len = strlen(keyword);
			row_len = strlen(secret)/col_len;
			for(int i = 0; i < col_len; i++) {
				for (int j = 0; j < row_len; j++) {
						convert[j][i] = secret[i*row_len+j];
				}
			}
			
			vector< pair<char, int> > v;
			for (int i = 0; i < col_len; i++) {
					v.push_back(pair<char, int>(keyword[i], i));
			}
			sort(v.begin(), v.end(), cmp_func);
			
			vector< pair<char, int> >::iterator it = v.begin();
			for (int p = 0; it != v.end(); it++,p++) {
				int col = it->second;
				for (int i = 0; i < row_len; i++) {
						result[i][col] =  convert[i][p];
				}
			}
			
			for (int i = 0; i < row_len; i++) {
				for (int j = 0; j < col_len; j++) {
						cout << result[i][j];
				}
			}
			cout << endl;
		}
		
		

}