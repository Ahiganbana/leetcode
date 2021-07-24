#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    string result;

public:
    string reverseWords(string s) {
        vector<string> tmps;
        string tmp = "";
        string result = "";
        int len = s.length();
        if(len != 0) {
            for (int i = len - 1; i >= 0; i--) {
                if(s[i] == ' ') {
                    tmps.push_back(tmp);
                    tmp = "";
                }else if (i == 0) {
                    tmp += s[i];
                    tmps.push_back(tmp);
                }
                else{
                    tmp += s[i];
                }
            }
        }
        for (int i = tmps.size() - 1; i >= 0; i--){
            result += tmps[i] + " ";
        }
            return result;
    }
};

int main() {
    Solution solution;
    string s;
    getline(cin, s);
    string result = solution.reverseWords(s);
    cout << result << endl;
    system("pause");
    return 0;
}