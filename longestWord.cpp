#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_set<string> s;
        string longest = "";
        for (int i = 0; i < words.size(); ++i) {
            s.insert(words[i]);
        }

        for(string word : words) {
            if(word.length() > longest.length() || word.length() == longest.length() && word < longest) {
                bool good = true;
                for (int k = 1; k < word.length(); ++k) {
                    if(!s.count(word.substr(0, k))) {
                        good = false;
                        break;
                    }
                }
                if(good) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};




int main() {
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Solution solution;
    string result = solution.longestWord(words);
    cout << result << endl;
    system("pause");
    return 0;
}