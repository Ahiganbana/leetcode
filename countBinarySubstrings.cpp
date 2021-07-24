#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //找到具有相同数量0和1的连续子字符串的数量
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, size = s.size();
        while(ptr < size) {
            char c = s[ptr];
            int count = 0;
            while(ptr < size && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for(int i = 1; i < counts.size(); i++) {
            ans += min(counts[i],counts[i-1]);
        }
        return ans;
    }
};    