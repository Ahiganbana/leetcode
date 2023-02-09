#include <iostream>
#include <vector>
using namespace std;

int process(string str, int index) {
    if(str.size() == index) {
        return 1;
    }

    if (str[index] == '0') {
        return 0;
    }

    int res = process(str, index + 1);
    if(index == str.size() - 1) {
        return res;
    }
    if((str[index] - '0') * 10 + str[index + 1] - '0' < 27) {
        res += process(str, index + 2);
    }
    return res;
}

// 动态规划版本
int dpways(string str) {
    if(str.size() < 1) {
        return 0;
    }
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = str[n - 1] == '0' ? 0 : 1;
    for (int i = n - 2; i >= 0; i--) {
        if(str[i] == '0') {
            dp[i] = 0;
        }else {
            dp[i] = dp[i + 1] + (((str[i] - '0') * 10 + str[i + 1]) < 27 ? dp[i + 2] : 0);
        }
    }
    return dp[0];
}    

int main() {
    string s = "111143311";
    int result = process(s, 0);
    int dpresult = process(s, 0);
    cout << result << endl;
    cout << dpresult << endl;
    system("pause");
    return 0;
}
