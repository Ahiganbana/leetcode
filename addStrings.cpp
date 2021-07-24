#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int length1 = num1.length() - 1, length2 = num2.length() - 1, add = 0;
        string ans = "";
        while (length1 >= 0 || length2 >= 0 || add != 0){
            //拿出每一位,如果位数不同实现高位补0
            int x = length1 > 0 ? num1[length1] - '0' : 0;
            int y = length2 > 0 ? num2[length2] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            length1--;
            length2--;
        }
        reverse(ans.begin(), ans.back());
        return ans;
    }
};

int main() {
    string input1, input2;
    cin >> input1 >> input2;
    Solution solution;
    string result = solution.addStrings(input1, input2);
    cout << result << endl;
    system("pause");
    return 0;
}