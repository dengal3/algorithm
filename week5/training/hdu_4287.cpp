#include <iostream>
#include <map>
#include <string>
using namespace std;

string getNum(char ch) {
	if (ch >= 'a' && ch <= 'c') {
		return "2";
	} else if (ch >= 'd' && ch <= 'f') {
		return "3";
	} else if (ch >= 'g' && ch <= 'i') {
		return "4";
	} else if (ch >= 'j' && ch <= 'l') {
		return "5";
	} else if (ch >= 'm' && ch <= 'o') {
		return "6";
	} else if (ch >= 'p' && ch <= 's') {
		return "7";
	} else if (ch >= 't' && ch <= 'v') {
		return "8";
	} else if (ch >= 'w' && ch <= 'z') {
		return "9";
	} 
}

string encode(string a) {
	string result = "";
	for (int i = 0; i < a.length(); i++) {
		result += getNum(a[i]);
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int count[5005] = {0};
		map<string, string> dict;
		map<string , int> seqs;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string seq;
			cin >> seq;
			seqs.insert(pair<string, int>(seq, i));
		}
		for (int i = 0; i < m; i++) {
			string term;
			cin >> term;
			string num_term = encode(term);
			dict.insert(pair<string, string>(term, num_term));
		}
		for (map<string, string>::iterator it = dict.begin(); it != dict.end(); it++) {
				if (seqs.count(it->second) > 0) {
						count[seqs.find(it->second)->second]++;
				}
		}
		for (int i = 0; i < n; i++) {
				cout << count[i] << endl;
		}
	}
}