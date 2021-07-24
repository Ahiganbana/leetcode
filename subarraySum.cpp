#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//找出数组中和为k的连续的子数组的个数
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //和为键, 出现的次数为值.
        unordered_map<int, int> m;
        int count = 0, pre = 0;
        m[0] = 1;
        for(auto& x : nums) {
            pre += x;
            if(m.find(pre - k) != m.end()) {
                count += m[pre - k];
            }
            m[pre] ++;
        }
        return count;
    }
};

int main() {
    int n, k = 0;
    cin >> n >> k;
    Solution solution;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    int result = solution.subarraySum(nums, k);
    cout << result << endl;
    system("pause");
    return 0;
}