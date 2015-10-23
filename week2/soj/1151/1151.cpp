#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <sstream>
using namespace std;
const int MAX = 11;

struct Step {
        int i;  // the ith in queue
        int x;   // x value
        int y;  // y value
        char op;  // 'A','B','C' or '-'
        int pre;    // the parent step's ith;
        int level;
        
        Step (int _i, int _x, int _y, char _op, int _pre, int _level) {
                i = _i;
                x = _x;
                y = _y;
                op = _op;
                pre = _pre;
                level = _level;
        }
		
		bool operator < (const Step& other) const {
			if (this->x == other.x && this->y == other.y) {
					return false;
			}
			return true;
		}
};

struct stringComp {
		bool operator() (const string& a, const string& b) const {
				return a > b;
		}
};

int target_x,  target_y;
int m, n;
int fp, rp;
vector<Step> qm;
set< pair<int, int> > s;  //  set
bool flag;
int M;
bool overflow;

string toString(int a) {
		stringstream convert;
		string result;
		
		convert << a;
		result = convert.str();
		
		return result;
}

void Aop() {
        m = qm[fp].y;
        n = qm[fp].x;
}

void Bop() {
        m = (qm[fp].x%10)*1000 + (qm[fp].x/10);
        n= (qm[fp].y%10)*1000 + (qm[fp].y/10);
}

void Cop() {
        int i = (qm[fp].x/1000)*1000;
        int j = qm[fp].x-i;
        int a = j/100;
        int b = (j-a*100)/10;
        int i1 = (qm[fp].y/1000)*1000;
        int j1 = qm[fp].y-i1;
        int c = j1/100;
        int d = (j1-c*100)/10;
        m = i + c*100 + a*10 + qm[fp].x%10;
        n = i1 + d*100 + b*10 + qm[fp].y%10;
        //cout << m << '\t' << n << endl;
}

bool comp(char op) {
	Step newStep = *(new Step(rp, m, n, op, fp, qm[fp].level+1));
	if (s.find(pair<int, int>(m, n)) != s.end()) {
			return false;
	}
    rp++;
    qm.push_back(newStep);
	//s.insert(strcat(buf1, buf2));
	//s.insert(newStep);
	//s.insert(toString(m) + toString(n));
	s.insert(pair<int, int>(m, n));

    if (qm[rp].level > M) {
            overflow = true;
    }
    if (m == target_x && n == target_y) {
            flag = true;
    }
    //cout << qm[fp].level+1 << endl;
    return true;
}

void printtop() {
        stack<char> sop;
        int p = rp;
        
        while (p != 1) {
                sop.push(qm[p].op);
                p = qm[p].pre;
        }
        
        if (overflow || sop.size() > M) {
            cout << "-1" << endl;
            return;
        }
        cout << sop.size() << " "; 
        while(!sop.empty()) {
                char op = sop.top();
                sop.pop();
                cout << op;
        }
        cout << endl;
}
int main () {
        while (cin >> M && M != -1) {
                qm.clear();
				s.clear();
                char a, b, c, d;
				char buf1[4], buf2[4];
                cin >> a >> b >> c >> d;
                target_x = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                cin >> a >> b >> c >> d;
                target_y = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                
                Step first = *new Step(1, 1234, 8765,  '-', 0, 0);
                qm.push_back(first);
                qm.push_back(first);
				//s.insert(toString(1234) + toString(8765));
				s.insert(pair<int, int>(1234, 8765));
                fp = 1;
                rp=1;
                flag = false;
                overflow = false;
                if (qm[fp].x == target_x && qm[fp].y == target_y) {
                    flag = true;
                }
                while (!flag) {
                        Aop();
                        if(comp('A')) {
                                if (flag || overflow) {
                                        break;
                                }
                        }
    
                        Bop();
                        if(comp('B')) {
                                if (flag || overflow) {
                                        break;
                                }
                        }

                        Cop();
                        if(comp('C')) {
                                if (flag || overflow) {
                                        break;
                                }
                        }
                        fp++;
                }
                if (flag || overflow) {
                        printtop();
                }
        }
        return 0;
}                                 