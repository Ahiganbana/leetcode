#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        bool flag = false;
        vector<int> index;
        int i, j;
        for (i = 0; i < nums.size(); i ++){
            for (j = i + 1; j < nums.size(); j ++){
                if(nums[i] + nums[j] == target){
                    flag = true;
                    break;
                }
            }
            if(flag){
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }

        return {};
    }
};

int main(){
    vector<int> input;
    int target = 0;
    int num = 0;
    Solution solution;
    while(cin >> num && num != -1){
        input.push_back(num);
    }
    cin >> target;

    vector<int> result(solution.twoSum(input, target));
    for (int i = 0; i < result.size() - 1; i ++){
        cout << result[i] << ",";
    }
    cout << result[result.size() - 1]<<endl;
    system("pause");
    return 0;
}