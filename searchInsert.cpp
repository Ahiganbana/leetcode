#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        int index = 0;
        bool flag = false;
        for (int i = 0; i < nums.size();i++){
            if(nums[i] == target){
                index = i;
                flag = true;
                break;
            }
        }   
        if(!flag){
            for (int i = nums.size() - 1; i >= 0;i--){
                if(target > nums[i]){
                    index = i+1;
                    break;
                }
                else{
                    index = i;
                }
            }
        }
        return index;
    }

    int searchInsert_binarysearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right){
            mid = left +  (right - left) / 2 ;
            if(target > nums[mid]){
                left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};

int main(){
    Solution solution;
    vector<int> nums;
    int num = 0;
    while(num != -1){
        cin >> num;
        nums.push_back(num);
    }
    nums.pop_back();
    int target = 0;
    cin >> target;
    int result = solution.searchInsert_binarysearch(nums,target);
    cout << result;
    system("pause");
    return 0;
}