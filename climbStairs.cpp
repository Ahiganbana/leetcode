#include <iostream>
using namespace std;
/*动态规划练习
 * 1. 定义用于存放历史记录的数组,依据题意,数组中存放的为上楼的方法数
 * 2. 确定初始值 依据题意初始值为 n=1 , n = 2;
 * 3. 确定最后一次与之前的联系(最后一次上楼的方法数为从倒数第二个楼梯上
 * 和从倒数第一个楼梯上dp[i] = dp[i - 1] + dp[i - 2])
 * */
class Solution {
public:
    int climbStairs(int n) {
        int *currMethod = new int[n + 1];
        int methodSum = 0;
        currMethod[0] = 1;
        currMethod[1] = 2;
        for (int i = 2; i < n; i++) {
            currMethod[i] = currMethod[i - 1] + currMethod[i - 2];
        }
        methodSum = currMethod[n - 1];
        delete[] currMethod;
        return methodSum;
    }

    /*尝试对上述版本优化
    *将空间复杂度从O(n) 降为O(1)
    * 由于计算的时候只需要i-1,i-2的值,并不需要用到之前的值.
    * */
    int climbStairs_1(int n) {
        int currMethods = 3;
        int lastMethod = 2;
        int twoLastMethods = 1;
        if(n == 1){
            currMethods = 1;
        }
        else if(n == 2){
            currMethods = 2;
        }
        for (int i = 2; i < n; i++){
            currMethods = lastMethod + twoLastMethods;
            twoLastMethods = lastMethod;
            lastMethod = currMethods;
        }
        return currMethods;
    }
};

int main() {
    Solution solution;
    int n = 0;
    cin >> n;
    int result = solution.climbStairs(n);
    cout << result << endl;
    result = solution.climbStairs_1(n);
    cout << result << endl;
    system("pause");
    return 0;
}