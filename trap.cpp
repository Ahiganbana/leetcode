#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 2) {
            return 0;
        }
        int ans = 0;
        int L = 0, R = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while(L < R) {
            leftMax = leftMax > height[L] ? leftMax : height[L];
            rightMax = rightMax > height[R] ? rightMax : height[R];
            if(height[L] < height[R]) {
                // 可以先计算左边的瓶颈
                ans += max(leftMax - height[L], 0);
                ++L;
            }else {
                ans += max(rightMax - height[R], 0);
                --R;
            }
        }
        return ans;
    }
};


int main() {
    // {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
    vector<int> height = { 3, 1, 2, 5, 2, 4};
    Solution solution;
    int res = solution.trap(height);
    cout << res << endl;
    system("pause");
    return 0;
}