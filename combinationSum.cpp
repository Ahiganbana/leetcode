#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//没有重复元素的数组求给定数字和的所有解集,每个数字可以反复选取
class Solution{
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

public:
    void DFS(int start, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0;
        i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }
};

int main(){
    vector<int> nums;
    int num = 0;
    while(num != -1){
        cin >> num;
        nums.push_back(num);
    }
    nums.pop_back();
    int target = 0;
    cin >> target;
    Solution solution;
    vector<vector<int>> result = solution.combinationSum(nums, target);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}