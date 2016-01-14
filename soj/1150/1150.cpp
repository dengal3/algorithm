#include <iostream>
#include <vector>
#include <stack>
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
};

int target_x,  target_y;
int m, n;
int fp, rp;
vector<Step> qm;
bool flag;
int M;
bool overflow;

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
    for (int i = 1; i <= rp; i++) {
            if (m == qm[i].x && n == qm[i].y) {
                return false;
            }
    }
    rp++;
    qm.push_back(*(new Step(rp, m, n, op, fp, qm[fp].level+1)));
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
                char a, b, c, d;
                cin >> a >> b >> c >> d;
                target_x = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                cin >> a >> b >> c >> d;
                target_y = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                
                
                qm.push_back(*new Step(1, 1234, 8765,  '-', 0, 0));
                qm.push_back(*(new Step(1, 1234, 8765,  '-', 0, 0)));
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