#include <iostream>
#include <vector>
using namespace std;

//求出数组中两个最大数的间隔乘积
class Solution {
public:
    int maxArea1(vector<int>& height) {
        int size = height.size();
        int tmp = 0;
        for (int i = 0; i < size; i++){
            for (int j = i + 1; j < size; j++){
                tmp = max(tmp, (j - i) * min(height[i], height[j]));
            }
        }
        return tmp;
    }

    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int tmp = 0;
        while(left < right) {
            tmp = max(tmp, (right - left) * min(height[left], height[right]));
            if(height[left] <= height[right]) {
                left++;
            }else{
                right--;
            }
        }
        return tmp;
    }
};