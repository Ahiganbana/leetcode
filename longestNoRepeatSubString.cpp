#include <iostream>
#include <vector>
using namespace std;

int maxUnique(string str) {
    if(str.size() == 0) {
        return 0;
    }

    vector<int> mp(256, -1);

    int len = 0;
    int pre = -1;
    int cur = 0;
    for (int i = 0; i != str.size(); ++i) {
        // 上一个重复字符出现的位置的最大值
        pre = max(pre, mp[str[i]]);
        // 当前子串的长度
        cur = i - pre;
        len = max(len, cur);
        mp[str[i]] = i;
    }
    return len;
}