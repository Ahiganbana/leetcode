#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution {
    int res = 0;
	vector<string> path;
public:
    /* Write Code Here */
    int partitionNumber(string text) {
        backtrack(text, 0);
        return res;
    }

	// 回溯找到所有的分割方式
	void backtrack(string &s, int index) {
        if(index >= s.size()) {
            // 找到一种分割方式
            res += 1;
            return;
        }
        
        for(int i = index; i < s.size(); ++i) {
            string str = s.substr(index, i - index + 1);
            if(isPalindromeStr(str) >= 2 || str.size() == 1) {
                path.push_back(str);
            }else {
                continue;
            } 
            backtrack(s, i + 1);
            path.pop_back();
        }
    }

    // 判断将字符串分成几段能够变成段式回文
    int isPalindromeStr(const string &s) {
        int n = s.size();

        for (int i = 1; i <= n / 2; ++i) {
            if(s.substr(0, i) == s.substr(n - i, i)) {
                return 2 + isPalindromeStr(s.substr(i, n - 2 * i));
            }
        }
        return n == 0 ? 0 : 1;
    }
};

int main() {
    int res;

    string _text;
    getline(cin, _text);
    Solution s;
    res = s.partitionNumber(_text);
    cout << res << endl;
    system("pause");
    return 0;

}
