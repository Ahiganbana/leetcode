#include <iostream>
#include <vector>
using namespace std;

// 计算必须以i 开头,总长度为len的字符串有多少个
int g(int i, int len){
    int sum = 0;
    if(len == 1) {
        return 1;
    }
    for (int j = i + 1; j <= 26; ++j) {
        sum += g(j, len - 1);
    }
    return sum;
}

// 计算长度为len的字符串有多少个
int f(int len) {
    int sum = 0;
    for (int i = 1; i <= 26; ++i) {
        sum += g(i, len);
    }
    return sum;
}

int Kth(string s) {
    int sum = 0;
    int len = s.size();
    int first = s[0] - 'a' + 1;
    // 按长度计算
    for (int i = 1; i < len; ++i) {
        sum += f(i);
    }
    int pre = first;

    // 按第一个字母计算
    for (int i = 1; i < first; ++i) {
        sum += g(i, len);
    }

    // 按后续字母依次计算
    for (int i = 1; i < len; ++i) {
        int cur = s[i] - 'a' + 1;
        for (int j = pre + 1; j < cur; ++j) {
            sum += g(j, len - 1);
        }
        pre = cur;
    }
    return sum + 1;
}