// KMP算法
#include <iostream>
#include <vector>
using namespace std;

int getIndexOf(string &s, string &m) {
    if(s.size() == 0 || m.size() == 0 || s.size() < m.size()) {
        return -1;
    }

    int i1 = 0;
    int i2 = 0;
    vector<int> next = getNextArray(m);

    while(i1 < s.size() && i2 < m.size()) {
        if(s[i1] == m[i2]) {
            i1++;
            i2++;
        }else if(i2 == 0) {
            i1++;
        } else {
            i2 = next[i2];
        }
    }
    return i2 == m.size() ? i1 - i2 : -1;
}

vector<int> getNextArray(string &ms) {
    if(ms.length() == 1) {
        return {-1};
    }
    vector<int> next(ms.length(), 0);
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0; // 拿哪个位置的字符和i-1位置的字符比 
    // next[i]存放的是(0,i)的子串中,前缀和后缀相等的最长的长度
    while(i < next.size()) {
        if(ms[i - 1] == ms[cn]) {
            next[i++] = ++cn;
        }
        else if(cn > 0) {
            cn = next[cn];
        }
        else {
            next[i++] = 0;
        }
    }
    return next;
}
