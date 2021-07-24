#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> res;
    vector<string> letterMap;

public:
    vector<string> letterCombinations(string digits) {
        letterMap = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits == "") {
            return res;
        }
        dfs(digits, 0, "");
        return res;
    }

    void dfs(string &digtis, int index, string s) {
        if(index == digtis.length()) {
            res.push_back(s);
            return;
        }
        char num = digtis[index];
        string letter = letterMap[num - '0'];
        for (int i = 0; i < letter.length(); ++i) {
            dfs(digtis, index + 1, s + letter[i]);
        }
    }
};