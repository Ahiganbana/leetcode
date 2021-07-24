#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int romanToInt(string s) {
        // write code here 
        unordered_map<char, int> base = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
                                       {'D', 500}, {'M', 1000}};
        
        int result = 0;
        string sub;
        for(int i = 0; i < s.size(); ++i) {
            int val = base[s[i]];
            if(i == s.size() - 1 || base[s[i + 1]] <= base[s[i]]) {
                result += val;
            }else {
                result -= val;
            }
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    int result = solution.romanToInt(s);
    cout << result << endl;
    system("pause");
    return 0;
}