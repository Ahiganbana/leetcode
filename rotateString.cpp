#include <iostream>
#include <vector>
using namespace std;

vector<int> getNextArray(string str) {
    int n = str.size();
    vector<int> next(n, 0);
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while(i < n) {
        if(str[i - 1] == str[cn]) {
            next[i++] = ++cn;
        }else if(cn > 0) {
            cn = next[cn];
        }else {
            next[i++] = 0;
        }
    }
    return next;
}

int getIndexOf(string s1, string s2) {
    if(s1.size() == 0 || s2.size() == 0 || s1.size() < s2.size()) {
        return -1;
    }
    vector<int> next = getNextArray(s2);
    int i1 = 0, i2 = 0;
    while(i1 < s1.size() && i2 < s2.size()) {
        if(s1[i1] == s2[i2]) {
            i1++;
            i2++;
        }else if(i2 == 0) {
            i1++;
        }else {
            i2 = next[i2];
        }
    }
    return i2 == s2.size() ? i2 - i1 + 1 : -1;
}

bool isRotateString(string a, string b) {
    if(a.size() != b.size()) {
        return false;
    }
    string c = a + a;
    int flag = getIndexOf(c, b);
    if(flag != -1) {
        return true;
    }else {
        return false;
    }
}

int main() {
    string s1 = "12345";
    string s2 = "45123";
    bool res = isRotateString(s1, s2);
    cout << res << endl;
    system("pause");
    return 0;
}