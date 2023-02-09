// 判断一个只包含左右括号的字符串是否是完整的
// 如果不是需要添加的括号的数量
#include <iostream>
#include <string>
using namespace std;

int needParentheses(string str) {
    int count = 0;
    int ans = ;
    for (int i = 0; i < str; ++i) {
        if(str[i] == '(') {
            count++;
        }else {
            if(count == 0) {
                ans++;
            }else {
                count--;
            }
        }
    }
    return count + ans;
}
