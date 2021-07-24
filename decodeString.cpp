#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    string res;

public:
    string decodeString1(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while(ptr < s.size()) {
            char cur = s[ptr];
            if(isdigit(cur)) {
                string digets = getDigets(s, ptr);
                stk.push_back(digets);
            }else if(isalpha(cur) || cur == '['){
                stk.push_back(string(1, s[ptr++]));
            }else{
                ++ptr;
                vector<string> sub;
                while(stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while(repTime--) {
                    t += o;
                }
                stk.push_back(t);
            }
        }

        return getString(stk);
    }

    string getDigets(string& s, size_t &ptr) {
        string ret = "";
        while(isdigit(s[ptr])) {
            res.push_back(s[ptr++]);
        }
        return res;
    }

    string getString(vector<string> &v) {
        string res;
        for(const auto &s : v) {
            res += s;
        }
        return res;
    }

    string decodeString(string s) {
        string res = "";
        stack<int> nstk;
        stack<string> sstk;

        int num = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }else if(isalpha(s[i])){
                res += s[i];
            }else if(s[i] == '[') {
                nstk.push(num);
                num = 0;
                sstk.push(res);
                res = "";
            }else{
                int times = nstk.top();
                nstk.pop();
                for (int j = 0; j < times; ++j) {
                    sstk.top() += res;
                }
                res = sstk.top();
                sstk.pop();
            }
        }
        return res;
    }

};


int main() {
    string s;
    cin >> s;
    Solution solution;
    string res = solution.decodeString1(s);
    cout << res;
    system("pause");
    return 0;
}