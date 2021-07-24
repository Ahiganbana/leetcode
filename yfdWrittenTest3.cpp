#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    vector<string> strs(T, "");
    for (int i = 0; i < T; ++i) {
        string s;
        getline(cin, s);
        strs[i] = s;
    }

    for (int i = 0; i < T; ++i) {

    }
}

void revolve(string &s) {
    stack<char> opt_stk;
    stack<char> dig_stk;
    size_t ptr = 0;
    while(ptr < s.size()) {
        char cur = s[ptr];
        
    }
}