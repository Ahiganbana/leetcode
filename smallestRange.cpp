#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //用于指明左边界和右边界
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        //使用数组维护每个列表中的指针
        vector<int> next(size);
        auto cmp = [&](const int &u, const int &v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };

        //使用优先队列,维护一个小顶堆
        priority_queue<int, vector<int>, decltype(cmp)>> pq(cmp);
        int minVal = 0, maxVal = INT_MIN;
        for (int i = 0; i < size; i++) {
            pq.emplace(i);
            //使用最小值中的最大值初始化右边界
            maxVal = max(maxVal, nums[i][0]);
        }

        //遍历左边界
        while(true) {
            int row = pq.top();
            pq.pop();
            minVal = nums[row][next[row]];
            //更新最小边界
            if(maxVal - minVal < rangeRight - rangeLeft) {
                rangeLeft = minVal;
                rangeRight = maxVal;
            }

            //如果遍历完了其中一个数组
            if(next[row] == nums[row].size) {
                break;
            }
            ++next[row];
            maxVal = max(maxVal, nums[row][next[row]]);
            pq.emplace(row);
        }
        return {rangeLeft, rangeRight};
    }
};