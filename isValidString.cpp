#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string str){
    if(str[0] != '-' && str[0] < '0' || str[0] > '9') {
        return false;
    }
    if (str[0] == '-' && (str.size() == 1 || str[1] == '0')) {
        return false;
    }
    if (str[0] == '0' && str.size() == 1) {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) {
        if(str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

// 将string转为int
// 技巧: 无论是正是负都按照负数进行转化,因为负数表达的数的绝对值比正数大一个
int strToInt(string str) {
    if(!isValid) {
        cout << "can not convert" << endl;
        return -1;
    }
    bool neg = str[0] == '-' ? true : false;
    const int minq = INT_MIN / 10;
    const int minr = INT_MIN % 10;
    int res = 0;
    int cur = 0;
    for (int i = neg ? 1 : 0; i < str.size(); ++i) {
        cur = '0' - str[i];
        if(res < minq || (res == minq && cur < minr)) {
            cout << "cannot convert" << endl;
            return -1;
        }
        res = res * 10 + cur;
    }
    if(!neg && res == INT_MIN) {
        cout << " cannot convert" << endl;
        return -1;
    }
    return neg ? res : -res;
}