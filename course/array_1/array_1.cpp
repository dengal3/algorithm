#include<iostream>
#include<fstream>
using namespace std;
const char *FILE_PATH = "test.txt";

int main() {
	ifstream ifile(FILE_PATH);
	int count_char[26] = {0};
	char hold;
	
	while (ifile.get(hold) && hold != '?') {
		count_char[hold-'a']++;
	}
	ifile.close();
	// output the result
	for (int i = 0; i < 26; i++) {
		cout << char('a'+i)<< '\t' <<  count_char[i] << endl;
	}
	return 0;
}