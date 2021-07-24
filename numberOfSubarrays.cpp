#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        int odd = 0, res = 0;
        vector<int> count(n + 1, 0);
        count[0] = 1;
        for (int i = 0; i < n; ++i) {
            odd += nums[i] & 1;
            res += odd >= k ? count[odd - k] : 0;
            count[odd] += 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = solution.numberOfSubarrays(nums, k);
    cout << result << endl;
    system("pause");
    return 0;
}