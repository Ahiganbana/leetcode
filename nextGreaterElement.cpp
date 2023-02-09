#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> res;
        vector<int> v;
        for(int i = 0; i < nums2.size(); ++i) {
            if(stk.empty() || nums2[i] < stk.top()) {
                stk.push(nums2[i]);
            }else {
                while(!stk.empty() && nums2[i] > stk.top()) {
                    int t = stk.top();
                    res.insert(make_pair(t, nums2[i]));
                    stk.pop();
                }
                stk.push(nums2[i]);
            }
        }
        while(!stk.empty()) {
            int t = stk.top();
            res.insert(make_pair(t, -1));
            stk.pop();
        }
        for(int i = 0; i < nums1.size(); ++i) {
            v.push_back(res[nums1[i]]);
        }
        return v;
    }
};

int main() {
    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;
    vector<int> nums1(n1, 0);
    vector<int> nums2(n2, 0);
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }
    Solution solution;
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    system("pause");
    return 0;
}