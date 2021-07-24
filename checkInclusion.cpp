#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        vector<int> s1map(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1.at(i) - 'a']++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); i++){
            vector<int> s2map(26, 0);
            for (int j = 0; j < s1.length(); j++) {
                s2map[s2.at(i + j) - 'a']++;
            }
            if (matches(s1map, s2map)){
                return true;
            }
        }
        return false;
    }

    bool matches(vector<int>& s1map, vector<int>& s2map) {
        for (int i = 0; i < 26; i++) {
            if(s1map[i] != s2map[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    Solution s;
    bool result = s.checkInclusion(s1, s2);
    cout << result << endl;
    //cout << s1 << s2 << endl;
    system("pause");
    return 0;
}