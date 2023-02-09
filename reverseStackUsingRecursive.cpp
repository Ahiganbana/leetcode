// 使用递归逆序一个栈
#include <iostream>
#include <stack>
using namespace std;

// 找到栈底元素并返回
int f(stack<int> &s) {
    int result = s.top();
    s.pop();
    if(s.empty()) {
        return result;
    }else {
        int last = f(s);
        s.push(result);
        return last;
    }
}

void reverse(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int i = f(s);
    reverse(s);
    s.push(i);
}