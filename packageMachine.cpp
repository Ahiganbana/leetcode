#include <iostream>
#include <vector>
using namespace std;

int minOpts(vector<int> &nums) {
    if(nums.size() == 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if(sum % nums.size() != 0) {
        return -1;
    }
    int avg = sum / nums.size();
    int leftSum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int leftRest = leftSum - i * avg;
        int rightRest = (sum - leftSum - nums[i]) - (nums.size() - i - 1) * avg;
        if(leftRest < 0 && rightRest < 0) {
            ans = max(ans, abs(leftRest) + abs(rightRest));
        } else {
            ans = max(ans, max(abs(leftRest), abs(rightRest)));
        }
        leftSum += nums[i];
    }
    return ans;
}