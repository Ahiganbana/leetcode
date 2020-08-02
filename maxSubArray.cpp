#include <iostream>
#include <vector>
#include <limits.h>
#include<algorithm>
using namespace std;

class Solution{
public :
    /*使用滑动窗口解决*/
    int maxSubArray(vector<int>& nums){
        int isAllMinus = 1;
        int maxNum = 0;
        int sum = 0;
        int start = 0;
        int end = 0;
        int numsSize = nums.size();
        if(numsSize == 0){
            return 0;
        }
        if(numsSize == 1){
            return nums[0];
        }
        /*数组中有正数*/
        for (int i = 0; i < numsSize;i++){
            if(nums[i] > 0){
                isAllMinus = 0;
                break;
            }
        }

        /*数组中全部为负数
         *返回最大的负数
        */
        if(isAllMinus == 1){
            for (int i = 0; i < numsSize;i++){
                maxNum = (maxNum > nums[i]) ? maxNum : nums[i];
                }
                return maxNum;
        }
        /*
         *使用第一个正数作为滑动窗口的起始位置
        */
        for (int i = 0; i < numsSize; i++){
            if(nums[i] > 0){
                start = i;
                break;
            }
        }
        /*
         *最后一个数即为起始位置
        */
        if(numsSize - 1 == start){
            return nums[start];
        }
        /*
         *不断改变滑窗的位置并对其中的元素求和
        */
        end = start;
        sum = 0;
        while(end < numsSize){
            sum += nums[end];
            if(sum > maxNum) {
                maxNum = sum;
            }else if(sum <= 0) {
                start = end;
                sum = 0;
            }
            end++;
        }
        return maxNum;
    }

    /*使用分治算法
     *1. 定义基本情况
      2. 将问题分解为子问题并递归地解决
      3. 合并子问题地解以获得原始问题地解(分治算法的
      使用条件之一即为子问题的组合能否合并为原问题的解)
     */
    int crossSum(vector<int>& nums, int left, int right, int p) {
        if(left == right) {
            return nums[left];
        }
        int leftSubsum = INT_MIN;
        int currSum = 0;
        for (int i = p; i > left - 1; --i) {
            currSum += nums[i];
            leftSubsum = max(leftSubsum, currSum);
        }
        int rightSubsum = INT_MIN;
        for (int i = p + 1; i < right + 1; ++i) {
            currSum += nums[i];
            rightSubsum = max(rightSubsum, currSum);
        }
        return leftSubsum + rightSubsum;
    }

    int helper(vector<int>& nums, int left, int right) {
        if(left == right){
            return nums[left];
        }

        int p = (left + right) / 2;

        int leftSum = helper(nums, left, p);
        int rightSum = helper(nums, p + 1, right);
        int cross_sum = crossSum(nums, left, right, p);

        return max(max(leftSum, rightSum), cross_sum);
    }

    int maxSubArray_2(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    /*动态规划思想
     *1.定义存放历史数据数组,数组中应该存放之前计算的和 
     *2.定义初始值
     *3.计算最后的结果与之前的之间的联系
    */

   int maxSubArray_3(vector<int>& nums) {
       int numsSize = nums.size();
       //存放当前和最大值的dp数组
       int *currMaxSum = new int[numsSize + 1];

       //存放当前和
       int sum = nums[0];
       //确定初始值
       currMaxSum[0] = sum;

       //根据公式更新
       for (int i = 1; i < numsSize; i++) {
           if(nums[i] > sum && sum < 0){
               sum = nums[i];
           }else{
               sum = sum + nums[i];
           }
           if(sum > currMaxSum[i-1] ){
               currMaxSum[i] = sum;
           }
           else{
               currMaxSum[i] = currMaxSum[i - 1];
           }
       }
       sum = currMaxSum[numsSize - 1];
       delete[] currMaxSum;
       return sum;
   }
};

int main(){
    Solution solution;
    vector<int> nums;
    int n = 0;
    while(n != -100){
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    int result = solution.maxSubArray(nums);
    int result1 = solution.maxSubArray_2(nums);
    int result2 = solution.maxSubArray_3(nums);
    cout << result << endl;
    cout << result1 << endl;
    cout << result2 << endl;
    system("pause");
    return 0;
}