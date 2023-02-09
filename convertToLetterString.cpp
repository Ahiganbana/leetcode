// 将数字字符串转为字母字符串
#include <iostream>
#include <vector>
using namespace std;

int process(string & s, int i) {
    if (i == s.length()) {
        return 1;
    }
    if(s[i] == '0') {
        return 0;
    }
    if(s[i] == '1') {
        int res = process(s, i + 1); // 将i单独作为一种情况后续有多少种方法
        if(i + 1 < s.length()) {
            res += process(s, i + 2); // 将 i 和后面的数一起作为一种情况后续有多少种方法
        }
        return res;
    }
    if(s[i] == '2') {
        int res = process(s, i + 1); 
        if(i + 1 < s.length() && (s[i + 1] >= '0' && s[i + 1] <= '6')) {
            res += process(s, i + 2);
        }
        return res;
    }
    process(s, i + 1);
}

