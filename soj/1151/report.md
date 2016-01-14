##soj 1151 魔板
###原题大意：
魔板由8个大小相同方块组成，分别用涂上不同颜色，用1到8的数字表示。
其初始状态是
1 2 3 4
8 7 6 5
对魔板可进行三种基本操作：
A操作（上下行互换）：
8 7 6 5
1 2 3 4
B操作（每次以行循环右移一个）：
4 1 2 3
5 8 7 6
C操作（中间四小块顺时针转一格）：
1 7 2 4
8 6 3 5
用上述三种基本操作，可将任一种状态装换成另一种状态。

输入包括多个要求解的魔板，每个魔板用三行描述。
第一行步数N（可能超过10的整数），表示最多容许的步数。
第二、第三行表示目标状态，按照魔板的形状，颜色用1到8的表示。
当N等于-1的时候，表示输入结束

对于每一个要求解的魔板，输出一行。
首先是一个整数M，表示你找到解答所需要的步数。接着若干个空格之后，从第一步开始按顺序给出M步操作（每一步是A、B或C），相邻两个操作之间没有任何空格。
注意：如果不能达到，则M输出-1即可。

本题的解题算法思想广搜。
使用的主要数据结构有一下：

    int target_x, target_y; // 目标值
    int m, n; // 现在的值
    int fp; // 指向队列头
    int rp; // 指向队列尾
    bool flag; //判断是否已经找到目标值
    bool overflow; // 判断此时是否已经超过步数限制的最大值
    struct Step{
        int i; // the ith in qm，相当于id
        int x; // x
        int y; // y
        char op; // 对应的操作'A','B','C'
        int pre; // 上一步的id
        int level; // 记录第一层的操作，用来和M做判断
        }; // 记录每一个步的信息
    vector<Step> qm; //记录所有步的容器，当做队列使用
    set<pair<int, int>> s; // 用来记录已经过的状态的set
                           // 这是为了减少判断是否已有状态的时间

### 解题思路
输入上限步数和目标值，初始化初始步（1234,8765），将这个放到队列中，fp和rp同时指向它，也放入s（set）中。
之后进入循环：
    取出当前队列的头的值，
    将这个值进行A操作得到进行A操作后的值，判断这个值时候已经遍历过了，若无，将这个值放到队列末尾，而且放入到状态集合set中，将这个值和目标状态进行比较，如果相同，flag设为1，即已经达到目标状态，结束循环。（B，C和A同理）

结束循环中，进行回溯输出：
    根据此时fp所指向的Step的pre属性，不断回溯到原始状态，在此过程中，将每个Step的操作值压栈。
    完成这个过程后，开始依次出栈输出从原始状态到目标状态的操作过程。

### 代码和注释解析
``` c++
#include <iostream>
#include <vector>
#include <stack>
#include <set>
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

int target_x,  target_y;
int m, n;
int fp, rp;
vector<Step> qm;
set< pair<int, int> > s;  //  set
bool flag;
int M;
bool overflow;

// A操作
void Aop() {
        m = qm[fp].y;
        n = qm[fp].x;
}

// B操作
void Bop() {
        m = (qm[fp].x%10)*1000 + (qm[fp].x/10);
        n= (qm[fp].y%10)*1000 + (qm[fp].y/10);
}

// C操作
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

// 查看状态是否已经存在了
bool comp(char op) {
    Step newStep = *(new Step(rp, m, n, op, fp, qm[fp].level+1));
    // 如果状态已存在，返回false
    if (s.find(pair<int, int>(m, n)) != s.end()) {
            return false;
    }
    rp++;  // 队列尾指针增加
    qm.push_back(newStep); // 将新状态放到队列尾
    s.insert(pair<int, int>(m, n));  // 将新状态放入集合中

    if (qm[rp].level > M) {     // 如果level>M，使overflow为true
            overflow = true;
    }
    if (m == target_x && n == target_y) {  // 如果等于目标状态，使flag为true
            flag = true;
    }
    return true;
}

// 用栈回溯输出操作过程
void printtop() {
        stack<char> sop; // 栈
        int p = rp;     // 队伍尾的下标
        
        while (p != 1) {    // 当未回溯到初始状态的节点时
                sop.push(qm[p].op);     // 将操作值压栈
                p = qm[p].pre;          // 把现在状态的父状态的id赋值给p
        }
        
        if (overflow || sop.size() > M) {   // 如果已经是超过了步数上限，返回-1
            cout << "-1" << endl;
            return;
        }
        cout << sop.size() << " ";     // 输出总步数大小
        while(!sop.empty()) {           // 出栈
                char op = sop.top();
                sop.pop();
                cout << op;
        }
        cout << endl;
}
int main () {
        while (cin >> M && M != -1) {  // 输入步数上限
                qm.clear();             // 清空队列
                s.clear();              // 清空状态集合
                char a, b, c, d;
                char buf1[4], buf2[4];
                cin >> a >> b >> c >> d;    // 以字符串形式输入x, y，转化为int
                target_x = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                cin >> a >> b >> c >> d;
                target_y = (a-'0')*1000 + (b-'0')*100 + (c-'0')*10 + (d-'0');
                
                Step first = *new Step(1, 1234, 8765, '-', 0, 0);
                qm.push_back(first);        // 将初始状态放到队列中
                qm.push_back(first);
                s.insert(pair<int, int>(1234, 8765));   // 将初始状态中放到状态集合中
                fp = 1;         // 初始fp，rp设为1
                rp=1;
                flag = false;
                overflow = false;
                // 如果初始状态是目标状态，令flag为true
                if (qm[fp].x == target_x && qm[fp].y == target_y) { 
                    flag = true;
                }
                while (!flag) {
                        // 进行A操作
                        Aop();
                        // 判断A操作过后的状态是否已经在之前到达过
                        if(comp('A')) {
                                // 如果该状态就是目标状态或者已经超过了步数上限
                                // 跳出循环
                                if (flag || overflow) {
                                        break;
                                }
                        }
    
                        // 进行B操作
                        Bop();
                        // 判断B操作过后的状态是否已经在之前到达过
                        if(comp('B')) {
                                // 如果该状态就是目标状态或者已经超过了步数上限
                                // 跳出循环
                                if (flag || overflow) {
                                        break;
                                }
                        }

                        // 进行C操作
                        Cop();
                        // 判断C操作过后的状态是否已经在之前到达过
                        if(comp('C')) {
                                // 如果该状态就是目标状态或者已经超过了步数上限
                                // 跳出循环
                                if (flag || overflow) {
                                        break;
                                }
                        }
                        // 队列头下标后移
                        fp++;
                }
                if (flag || overflow) {
                        printtop(); //输出
                }
        }
        return 0;
}                                 
```

### 测试数据：

1. 刚好目标状态就是初始状态。即输入1234 8765
2. 目标状态的所需步数刚好是上限步数。
3. 目标状态的所需步数刚好超过上限步数。

### 分析
代码相对于1150的在十步以内的改进是，在1150中查找状态是否已经存在是以顺序遍历一次队列的方式进行的，因为之前的步数要求只有10，所以不考虑操作状态的重复剪枝的话，就是最大有3^10个状态。顺序遍历的话每次都要搜索一次队列。而改进的算法是在搜索队列里面的状态的时候用了set这个结构，c++的set是二叉树的结构，这样的查找复杂度变成了O(logn)





