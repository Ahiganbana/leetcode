// 不使用加减乘除的符号完成两数的加减乘除操作
#include <iostream>
using namespace std;
int add(int a, int b) {
    int sum = a;
    while(b != 0) {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return sum;
}

int negNum(int &b) {
    return add(~b, 1);
}

int mins(int a, int b) {
    return add(a, negNum(b));
}

int multi(int a, int b) {
    int res = 0;
    while(b != 0) {
        if((b & 1) != 0) {
            res = add(res, a);
        }
        a <<= 1;
        b = (unsigned)b >> 1;
    }
    return res;
}

int isNeg(int n) {
    return n < 0;
}

int divide(int a, int b) {
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for (int i = 31; i > -1; i = mins(i, 1)) {
        if((x >> i) >= y) {
            res |= (1 << i);
            x = mins(x, y << i);
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

int main(){
    int a =-2147483648;
    int b = -1;
    int result = divide(a, b);
    cout << result << endl;
    system("pause");
    return 0;
}

class Solution {
public:
    int divide(int a, int b) {
        bool isNeg = false;
        if((a > 0) ^ (b > 0)) {
            isNeg = true;
        }
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = help(a, b);
        if(isNeg) return ans;
        if(ans == INT_MIN) return INT_MAX;
        return -ans;
    }

    int help(int a, int b) {
        if(a > b) return 0;
        int cur = b;
        int ans = -1;
        while(a - cur <= cur) {
            ans += ans;
            cur += cur;
        }
        return ans + help(a - cur, b);
    }
};