#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
    string countAndSay(int n) {
        string s = "1";
        string result = "";
        for (int i = 1; i < n; i++) {
            string tmp;
            for (int j = 0; j < s.size(); j++) {
                int count = 1;
                while (j + 1 < s.size() && s[j+1] == s[j]){
                    count++;
                    j++;
                }
                tmp += to_string(count) + s[j];
            }
            s = tmp;
        }
        return s;
    }
};

int main(){
    Solution solution;
    int n = 0;
    cin >> n;
    string result = "";
    if(n >= 1 && n <= 30){
        result = solution.countAndSay(n);
        cout << result << endl;
    }
    system("pause");
    return 0;
}