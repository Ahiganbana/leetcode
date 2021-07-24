#include <iostream>
#include <vector>
using namespace std;

//找出数组中个数超过n / 3的集合
//摩尔根投票法
//基于事实: 如果要投出2名候选人,即他们得到的票数应该多于n/3
//即,集合中最多只有两个元素
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int times = size / 3;
        vector<int> res;
        if(size == 0) {
            return res;
        }
        int can1 = nums[0], count1 = 0;
        int can2 = nums[0], count2 = 0;
        //投票阶段
        for (int i = 0; i < size; ++i) {
            if(nums[i] == can1) {
                count1++;
                continue;
            }
            if(nums[i] == can2) {
                count2++;
                continue;
            }
            if(count1 == 0) {
                can1 = nums[i];
                count1++;
                continue;
            }
            if(count2 == 0) {
                can2 = nums[i];
                count2++;
                continue;
            }
            count1--;
            count2--;
        }
        //计数阶段
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < size; i++) {
            if(nums[i] == can1){
                count1++;
            }else if(nums[i] == can2) {
                count2++;
            }
        }
        if(count1 > times){
            res.push_back(can1);
        }
        if(count2 > times) {
            res.push_back(can2);
        }
        return res;
    }
};