#include <iostream>
#include <vector>
using namespace std;

//找出所有相加之和为 n 的 k 个数的组合
class Solution {
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(1, n, k, path);
        return result;
    }

    void dfs(int i, int n, int k, vector<int>& path) {
        if(path.size() == k && n == 0) {
            result.push_back(path);
        }

        for (int index = i; index < 10; ++index) {
            //剪枝
            if(n - index < 0) {
                return;
            }
            //选择
            path.push_back(index);
            //递归
            dfs(index + 1, n - index, k, path);
            //回溯
            path.pop_back();
        }
    }
};