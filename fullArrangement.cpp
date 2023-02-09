#include <iostream>
#include <vector>
#include <string>
using namespace std;

// str[i..]范围上 所有的字符都可以在i位置上出现,后续都需要尝试
// str[0,...i-1]是之前做出的选择
// 所有全排列形成的结果放入res
void process(string &str, int i, vector<string> &res) {
    if(i == str.size()) {
        res.push_back(str);
    }
    // 如果要求不重复 需要记录每个字符是否已经被访问过
    bool visit[26];
    for (int j = i; j < str.size(); ++j) {
        if (!visit[str[j] - 'a']) {
            visit[str[j] - 'a'] = 1;
            swap(str[i], str[j]);
            process(str, i + 1, res);
            swap(str[i], str[j]);
        }
    }
} 