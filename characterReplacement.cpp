#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        unordered_map<char, int> charCounter;
        int maxSize = 0;
        while(j < s.length()){
            charCounter[s[j]] += 1;
            maxSize = max(maxSize, charCounter[s[j]]);
            if((j - i + 1) - maxSize > k) {
                charCounter[s[i]] -= 1;
                i += 1;
            }
            j += 1;
        }
        return j - i;
    }
};

int main() {
    int k = 0;
    string s = "";
    cin >> s >> k;
    Solution solution;
    int result = solution.characterReplacement(s, k);
    cout << result << endl;
    system("pause");
    return 0;
}
