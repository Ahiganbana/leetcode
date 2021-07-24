#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//求a+b+c = sum,求与target最接近的sum值
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int diff = 1e7;
        sort(nums.begin(),nums.end());

        //计算差值
        auto update = [&](int cur) {
            if(abs(cur - target) < abs(diff - target))
            {
                diff = cur;
            }
        };
        //枚举a
        for (int first = 0; first < size; ++first){
            if(first > 0 && nums[first] == nums[first - 1]){
                continue;
            }
            int third = size - 1, second = first + 1;
            //枚举b,c
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) {
                    return target;
                }
                update(sum);
                if(sum > target) {
                    int third0 = third - 1;
                    while(second < third0 && nums[third0] == nums[third]){
                        --third0;
                    }
                    third = third0;
                }else{
                    int second0 = second + 1;
                    while(second0 < third && nums[second0] == nums[second]) {
                        ++second0;
                    }
                    second = second0;
                }
            }
        return diff;
    }
};