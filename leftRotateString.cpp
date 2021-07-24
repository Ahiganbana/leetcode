//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string s = str.substr(0, n);
        str = str.erase(0, n);
        return str + s;
    }
};

int main() {
    // string s;
    // int n = 0;
    // cin >> s >> n;
    // Solution solution;
    // string result = solution.LeftRotateString(s, n);
    // cout << result << endl;
    string s;
    cin >> s;
    cout << typeid(s[0]).name() << endl;
    system("pause");
    return 0;
}