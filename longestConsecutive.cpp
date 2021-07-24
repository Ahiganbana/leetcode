#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] - nums[i - 1] == 0) {
                continue;
            }
            if(nums[i] - nums[i - 1] == 1) {
                count++;
            }else {
                res = max(res, count);
                count = 1;
            }
        }
        return res;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num : nums) {
            num_set.insert(num);
        }

        int res = 0;
        for(const int& num : num_set) {
            if(!num_set.count(num)) {
                int current_num = num;
                int current_streak = 1;

                while(num_set.count(current_num - 1)) {
                    current_num += 1;
                    current_streak += 1;
                }

                res = max(res, current_streak);
            }
        }
        return res;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution solution;
    int result = solution.longestConsecutive(nums);
    cout << result << endl;
    system("pause");
    return 0;
}