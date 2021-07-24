#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        //计算每个字母出现的频率
        unordered_map<char, int> freq;
        for(auto c : s) {
            freq[c]++;
        }
        int i = 0, j = 0, res = n;
        for (; i < n;) {
            if(freq['Q'] > n / 4 || freq['W'] > n / 4 || freq['E'] > n / 4 || freq['R'] > n / 4) {
                if(j < n) {
                    freq[s[j]]--;
                    j++;
                }else{
                    break;
                }
            }
            else{
                res = min(res, j - i);
                freq[s[i]]++;
                i++;
            }
        }
        return res;
    }
};
