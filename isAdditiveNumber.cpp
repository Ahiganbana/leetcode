#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() == 0) {
            return false;
        }
        bool res = false;
        process(num, 0, 0, res);
        return res;
    }

    void process(const string &num, int startIndex, int endIndex, bool &res) {
        if(endIndex >= num.size()) {
            res = true;
            return;
        }

        for(int lengthOfa = 1; startIndex + lengthOfa <= num.size(); ++lengthOfa) {
            for(int lengthOfb = 1; lengthOfb + startIndex + lengthOfa <= num.size(); ++lengthOfb) {
                string a = num.substr(startIndex, lengthOfa);
                string b = num.substr(startIndex + lengthOfa, lengthOfb);

                // 判断是否有前导0
                if((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) {
                    continue;
                }

                string sum = addString(a, b);
                string c = num.substr(startIndex + lengthOfa + lengthOfb);

                // 判断是否能够组成
                if(sum.size() > c.size() || sum != c.substr(0, sum.size())) {
                    continue;
                }

                process(num, startIndex + lengthOfa, startIndex + lengthOfa + lengthOfb + sum.size(), res);
            }
        }
    }

    string addString(string &a, string &b) {
        int len = a.size() > b.size() ? a.size() : b.size();
        string c(len + 1, ' ');

        int ptra = a.size() - 1, ptrb = b.size() - 1, ptrc = c.size() - 1, thisNum = 0, carrySum = 0;
        
        while(ptra >= 0 || ptrb >= 0) {
            int numA = (ptra >= 0) ? a[ptra--] - '0' : 0;
            int numB = (ptrb >= 0) ? b[ptrb--] - '0' : 0;

            thisNum = numA + numB + carrySum;

            if(thisNum >= 10) {
                carrySum = 1;
                thisNum %= 10;
            }else {
                carrySum = 0;
            }
            c[ptrc--] = thisNum + '0';
        }

        if(carrySum > 0) {
            c[0] = '1';
            return c;
        }else {
            return c.substr(1);
        }
    }
}; 


int main() {
    Solution solution;
    string s = "112358";
    bool res = solution.isAdditiveNumber(s);
    cout << res << endl;
}