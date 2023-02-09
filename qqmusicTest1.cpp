#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return int整型
     */
    // 找到所有长度是k的子串 并从中找到最大的
    int maxValue(string s, int k) {
        // write code here
        if(k == s.size()) {
            return stoi(s);
        }
        
        int maxVal = -1;
        int left = 0;
        int right = left + k - 1;
        while(left < right && right < s.size()) {
            int curVal = 0;
            for(int i = left; i <= right; ++i) {
                curVal = curVal * 10 + (s[i] - '0'); 
            }
            maxVal = max(curVal, maxVal);
            ++left;
            ++right;
        }
        return maxVal;
    }
};

int main() {
    string s = "321";
    int n = 1;
    Solution solution;
    int res = solution.maxValue(s, n);
    cout << res << endl;
    system("pause");
    return 0;
}