#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key 是元素的值 value是元素在数组中的索引
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            if(m.find(target - nums[i]) != m.end()) {
                // 哈希表中有元素
                return {m[target - nums[i]], i};
            }else {
                m.insert(make_pair(nums[i], i));
            }
        }
        return {-1, -1};
    }
};

int main() {
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> input(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    Solution solution;
    vector<int> res = solution.twoSum(input, target);
    cout << res[0] << " " << res[1] << endl;
    system("pause");
    return 0;
}