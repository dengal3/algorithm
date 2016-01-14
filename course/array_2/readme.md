倒蛇阵填数，任给一个正整数n（n<=20），将1-n^2分别填入矩阵中，在显示器上输出如下格式

    n=3:
        7  8  1
        6  9  2
        5  4  3
    n=4:
        10  11  12  1
        9   16  13  2
        8   15  14  3
        7   6   5   4

关键问题：线性表元素值与下标i,j之间的关系

算法设计： 每圈四条边，顺序为右上->右下，右下->左下, 左下->左上,左上->右上

    第1圈四边:
    A[1,n]->A[n,n], A[n, n-1]->A[n, 1], A[n-1, 1]->A[1, 1], A[1, 2]->A[1, n-1]

    第i圈四边：
    1->i, n->n+1-i 代入第一圈的式子
    得
    A[i,n+1-i]->A[n+1-i,n+1-i], A[n+1-i,n-i]->A[n+1-i,i],
    A[n-i, i]->A[i, i], A[i, i+1]->A[i, n-i]

i=1开始赋值
当```i<n+1-i```时构成圈，当```i>n+1-i```结束
i=n+1-i则A[i, i]=n^2结束（最后填入的元素位）