#include <iostream>
#include <string>
#include <vector>
using namespace std;

//从给定的字符串中找到在字符串字典中最长的字符串
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string maxStr = "";
        for(auto str : d){
            if(isSubsequence(str, s)) {
                if(str.length() > maxStr.length() || (str.length() == maxStr.length() && str < maxStr)){
                    maxStr = str;
                }
            }
        }
        return maxStr;
    }

    bool isSubsequence(string x, string y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++) {
            if(x[j] == y[i]){
                j++;
            }
        }
        return j == x.length();
    }
};