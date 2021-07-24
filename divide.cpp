#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long dividendl = dividend, divisorl = divisor;
        bool isNegtive = false;
        if(dividend == 0) return 0;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            isNegtive = true;
        }
        if(divisor == -1) {
            if(dividend > INT_MIN) return -dividend;
            else return INT_MAX;
        }
        if(divisor == 1) {
            return dividend;
        }
        dividendl = dividend > 0 ? dividendl : -dividendl;
        divisorl = divisor > 0 ? divisorl : -divisorl;
        int res = div(dividendl, divisorl);
        if(!isNegtive) {
            return res > INT_MIN ? INT_MIN : res;
        }
        return -res;
    }

    int div(long a, long b) {
        if(a < b) return 0;
        long tb = b;
        int res = 1;
        while((tb + tb) <= a) {
            res = res + res;
            tb = tb + tb;
        }
        return res + div(a - tb, b);
    }
};

int main() {
    int dividend = 0, divisor = 0;
    cin >> dividend >> divisor;
    Solution solution;
    int result = solution.divide(dividend, divisor);
    cout << result << endl;
    system("pause");
    return 0;
}