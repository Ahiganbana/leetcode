// 递归方式求解
/**两人拿一组使用整型数组表示的牌.玩家A和玩家B只能从左右两边开始拿牌
 * 返回最后获胜者的分数
 * */
#include <iostream>
#include <vector>
using namespace std;

// 先手拿牌的情况
int first(vector<int> &arr, int i, int j) {
    if(i == j) {
        return arr[i];
    }
    // 先手拿了左边的牌 后手只能拿 i+ i,j范围里的牌
    // 先手拿了右边的牌 后手只能拿 i, j-1范围里的牌
    return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
}

int second(vector<int> &arr, int i, int j) {
    if(i == j) {
        return 0;
    }
    return min(first(arr, i + 1, j), first(arr, i, j - 1));
}

int win(vector<int> &arr) {
    return max(first(arr, 0, arr.size() - 1), second(arr, 0, arr.size() - 1));
}

// 动态规划
int win2(vecrtor<int> &arr) {
    int n = arr.size();
    vector<vector<int>> fdp(n, vector<int>(n, 0));
    vector<vector<int>> sdp(n, vector<int>(n, 0));
    return process(arr, fdp, sdp);
}

int process(vector<int> & arr, vector<vector<int>> &fdp, vector<vector<int>> &sdp) {
    // 初始化
    for (int i = 0; i < fdp.size(); ++i) {
        fdp[i][i] = arr[i];
        sdp[i][i] = 0;
    }

    // 动态规划
    int row = 0;
    int col = 1;
    while(col < arr.size()) {
        int i = row;
        int j = col;
        while(i < arr.size() && j < arr.size()) {
            fdp[i][j] = max(arr[i] + sdp[i + 1][j], arr[j] + sdp[i][j - 1]);
            sdp[i][j] = min(fdp[i + 1][j], f[i][j - 1]);
        }
        col++;
    }
    return max(fdp[0][n - 1], sdp[0][n - 1]);
}