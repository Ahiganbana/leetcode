#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val){
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            if(nums[0] == val){
                return 0;
            }
            else{
                return 1;
            }
        }
        int indexl = 0;
        int indexr = nums.size() - 1;
        while(indexl <= indexr){
            if(nums[indexl] == val){
                if(nums[indexr] != val){
                    int t = nums[indexl];
                    nums[indexl] = nums[indexr];
                    nums[indexr] = t;
                }
                else{
                    indexr--;
                }
            }
            else{
                indexl++;
            }
        }
        return indexl;
    }

    int removeElement1(vector<int>& nums, int val){
        int ans = 0;
        int num = 0;
        for (int i = 0; i < nums.size();i++){
            num = nums[i];
            if(nums[i] != val){
                nums[ans] = num;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    int num;
    vector<int> nums;
    while(cin >> num && num != -1){
        nums.push_back(num);
    }
    int val;
    cin >> val;
    Solution solution;
    //int result = solution.removeElement(nums,val);
    int result = solution.removeElement1(nums, val);
    cout << result << endl;
    for (int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}