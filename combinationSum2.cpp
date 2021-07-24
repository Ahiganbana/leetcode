#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//有重复元素的数组求给定目标和的解集,每个元素只能被一个组合选择一次
//保证每个数只使用一次 保证没有重复的集合
class Solution {
    vector<int> path;
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, target);
        return result;
    }
    void DFS(int start, vector<int>& candidates, int target) {
        int n = count(result.begin(), result.end(), path);
        if(target == 0 && n == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            path.push_back(candidates[i]);
            DFS(i + 1, candidates, target - candidates[i]);
            path.pop_back();
        }
    }
};