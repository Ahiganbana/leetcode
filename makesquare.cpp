#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求给出的火柴的数量和长度能否围城正方形
class Solution {
    vector<int> sums;
    int possibleSquareSide;
public:
    bool makesquare(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return false;
        }
        int perimeter = 0;
        sums.resize(4);
        for(int i = 0; i < size; ++i) {
            perimeter += nums[i];
        }
        possibleSquareSide = perimeter / 4;
        if(possibleSquareSide * 4 != perimeter) {
            return false;
        }
        sort(nums.begin(), nums.end());
        return dfs(0, nums);
    }

    bool dfs(int index, vector<int>& nums) {
        if(index == nums.size()) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }
        int curr = nums[index];
        for(int i = 0; i < 4; ++i) {
            if(sums[i] + curr <= possibleSquareSide) {
                sums[i] += curr;
                if(dfs(index + 1, nums)) {
                    return true;
                }
                sums[i] -= curr;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    bool result = solution.makesquare(nums);
    cout << result << endl;
    system("pause");
    return 0;
}