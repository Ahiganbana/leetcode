#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//合并输入的数组中两个重叠的子区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rows = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        if(rows == 0) {
            return result;
        }
        for (int i = 0; i < rows; ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if (!result.size() || left > result.back()[1]) {
                result.push_back({left, right});
            }else{
                result.back()[1] = max(right, result.back()[1]);
            }
        }
            return result;
    }   
};