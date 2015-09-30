#include<fstream>
#include<time.h>
#include<stdlib.h>
const int AMOUNT = 1000000;
using namespace std;

int main(int argc, char	*argv[]) {
	ofstream ofile;
	ofile.open("./test.txt");
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < AMOUNT; i++) {
		char ran_ch = rand()%26 + 'a';
		ofile << ran_ch;
	}
	ofile << '?';
	ofile.close();
	return 0;
}