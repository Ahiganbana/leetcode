// 找出最小的使数字全部为1的进制
#include<iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
public:
    string smallestGoodBase(string n) {
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; --m) {
            int k = pow(nVal, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; ++i) {
                mul *= k;
                sum += mul;
            }
            if(sum == nVal) {
                return to_string(k);
            }
        }
        return to_string(n - 1);
    }
};