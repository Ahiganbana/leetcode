#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l1 < l2) {
            return -1;
        }
        if(l2 == 0) {
            return 0;
        }
        int res = -1;
        int i = 0, j = 0;
        while(i < l1 && j < l2) {
            if(haystack[i] == needle[j]) {
                ++i;
                ++j;
            }else {
                ++i;
            }
        }
        if(j == l2) {
            // 说明needle是haystack的子串
            return i - l2;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    string str1 = "hello",str2 = "ll";
    // cin >> str1>>str2;
    int result = solution.strStr(str1, str2);
    cout << result << endl;
    system("pause");
    return 0;
}