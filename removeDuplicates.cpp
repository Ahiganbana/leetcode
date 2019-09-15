/*
    在原地使用O(1)的空间删除排序数组中的元素
 */
#include <iostream>
#include <vector>

using namespace std;
/* 
class Solution{
public :
    int removeDuplicates(vector<int>& nums){
        int index = nums.size();
        if(index == 0){
            return 0;
        }
        if(index == 1){
            return 1;
        }
        int length = 1;
        for (int i = 0; i < index - 1; i++){
            int j = i + 1;
            if(nums[i] != nums[j]){
                length++;
                nums[length - 1] = nums[j];
            }
        }
        return length;
    }
};
*/
//别人的实现方法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]!=nums[i])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

int main(){
    Solution solution;
    vector<int> nums;
    int num;
    while(cin >> num && num != -1){
        nums.push_back(num);
    }
    int length = solution.removeDuplicates(nums);
    cout << length << endl;
    for (int index = 0; index < length; index++){
        cout << nums[index] << " "; 
    }
        system("pause");
    return 0;
}