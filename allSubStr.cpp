// 打印字符串的所有子序列

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
void process(string &s, int i, string &res) {
    if(i == s.size()) {
        result.push_back(res);
        return;
    }
    string resKeep = res; 
    resKeep.append(s[i]);
    // 选择当前字符组成的子序列
    process(s, i + 1, resKeep);
    string resNoInclude = res;
    // 不选择当前字符组成的子序列
    process(s, i + 1, resNoInclude);
}
