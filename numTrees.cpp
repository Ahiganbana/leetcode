#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
    /**
 * 动态规划练习
 * 不同的二叉搜索树
 * 1.定义存放历史数据的数组 此题中数组里存放的是数字i所构成的二叉搜索树和的个数
 * 2.确定动态转移方程 已知n构成的二叉搜索树为卡特兰数 
 * 递归公式为h(n) = h(1)*h(n-1) + h(2)*h(n-2) + ... + h(n-1)*h(1);
 * 3.确定初始值 dp[0] = 0;dp[1] = 1;
 */
    int numTrees(int n) {
        vector<int> dp(n + 2, 0);
        if(n == 0) {
            return 0;
        }
        dp[1] = 1;
        int tmp = 0;
        for (int i = 2; i <= n + 1; i++) {
            for (int j = 1; j <= i; j++) {
               tmp = dp[j] * dp[i - j];
               dp[i] += tmp;
            }
        }
        return dp[n + 1];
    }
};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    int result = solution.numTrees(n);
    cout << result << endl;
    system("pause");
    return 0;
}