#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private: 
    static constexpr int SEG_COUNT = 4;
private: 
    vector<string> ans;
    vector<int> segments;
public:
    vector<string> restoreIpAddresses(string& s) {
       //从给定的字符串中找到所有可能组成的IP地址
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }

    void dfs(const string& s, int segId, int segStart) {
        //找到了4段IP并且遍历完了所有字符串,就是一种答案
        if(segId == SEG_COUNT) {
            if(segStart == s.size()) {
                string ipAddr;
                for(int i = 0; i < SEG_COUNT; ++i) {
                    ipAddr += to_string(segments[i]);
                    if(i != SEG_COUNT - 1) {
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr));
            }
            return ;
        }

        //找完所有字符串还没有找到4段IP
        if(segStart == s.size()) {
            return;
        }

        //消除前导0
        if(s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        int addr = 0;
        for(int segEnd = segStart; segEnd < s.size(); ++segEnd) {
            addr = addr * 10 + (s[segEnd] - '0');
            if(addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            }else{
                break;
            }
        }
    }
};   

int main() {
    string s;
    cin >> s;
    Solution solution;
    vector<string> result = solution.restoreIpAddresses(s);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    system("pause");
    return 0;
} 