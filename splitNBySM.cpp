#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> dicsSumAndCount(int n) {
    int sum = 0;
    int count = 0;
    // 求n的因子和所有因子的和
    for (int i = 2; i <= n; ++i) {
        while(n % i == 0) {
            sum += i;
            count++;
            n /= i;
        }
    }
    return {sum, count};
}

bool isPrim(int n) {
    for (int i = 0; i < sqrt(n); ++i) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int minOps(int n) {
    if(n < 2) {
        return 0;
    }
    if(isPrim(n)) {
        return n - 1;
    }

    // 不是质数
    vector<int> divSumAndCount = dicsSumAndCount(n);
    return divSumAndCount[0] - divSumAndCount[1];
}