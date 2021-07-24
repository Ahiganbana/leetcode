#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> res;
        int size = s.length();
        if(size == 0) {
            return res;
        }
        dfs(s, 0, cur, res);
        return res;
    }

    void dfs(string s, int idx, vector<string> cur,  vector<vector<string>>& res) {
        int start = idx;
        int end = s.length();
        if(start == end) {
            vector<string> tmp = cur;
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < end; ++i) {
            if(isPal(s, start, i)) {
                cur.push_back(s.substr(start, i + 1 - start));
                dfs(s, i + 1, cur, res);
                cur.pop_back();
            }           
        }
    }

    bool isPal(string s, int start, int end) {
        while (start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    vector<vector<string>> res = solution.partition(s);
    system("pause");
    return 0;
}