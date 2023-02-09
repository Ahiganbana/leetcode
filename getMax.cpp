#include <iostream>
using namespace std;

// 不使用比较找出两个数中较大的

// 负数返回0 非负数返回1
int sign(int n) {
    return flip((n >> 31) & 1);
}

int flip(int n) {
    // 负数返回0 非负数返回1
    return n ^ 1;
}

// 有可能溢出
int getMax1(int a, int b) {
    int c = a - b;
    int scA = sign(c); // a - b 非负, scA为1 a-b 为负, scA为0
    int scB = flip(scA); // scA 为 0, scB 为 1; scA为1, scB为0
    return a * scA + b * scB;
}

// 正确做法
int getMax2(int a, int b) {
    int c = a - b;
    int sa = sign(a); // a 是非负数返回1, 负数返回0
    int sb = sign(b);
    int sc = sign(c);
    int difSab = sa ^ sb; // a b的符号不一样为1;一样为0
    int sameSab = flip(difSab);
    int returnA = difSab * sa + sameSab * sc; // 返回a的情况 : a,b同号且相减得到的符号位是1, 或者a,b不同号且a是非负数
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}