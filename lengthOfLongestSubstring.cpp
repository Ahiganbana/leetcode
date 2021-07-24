#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//找出字符串中无重复字符的最长字串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int len = s.size();
        int right = -1, ans = 0;
        for (int i = 0; i < len; ++i) {
            if(i != 0) {
                us.erase(s[i - 1]);
            }
            while(right + 1 < len && !us.count(s[right + 1])) {
                us.insert(s[right + 1]);
                ++right;
            }
            ans = max(ans, right - i + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    int result = s.lengthOfLongestSubstring(str);
    cout << result << endl;
    system("pause");
    return 0;
}