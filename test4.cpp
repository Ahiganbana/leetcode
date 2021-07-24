#include<iostream>
using namespace std;


int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while(nums[left] >= nums[right]){
        mid = (left + right) / 2;
        if(right - left == 1) {
            mid = right;
            break;
        }
        else if(nums[mid] >= nums[right]) {
            left = mid;
        }else {
            right = mid;
        }
    }
    return nums[mid];
}

void find(int left, int right, vector<int>& nums) {
    while(nums[left] > nums[right]) {
        left = 
    }
}