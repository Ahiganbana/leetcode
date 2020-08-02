#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return buildTree(0, size - 1, nums);
    }

    TreeNode* buildTree(int begin, int end, vector<int> &nums) {
        if(begin > end) {
            return nullptr;
        }

        int mid = (begin + end) / 2;
        TreeNode *tree = new TreeNode(nums[mid]);
        tree->left = buildTree(begin, mid - 1, nums);
        tree->right= buildTree(mid + 1, end, nums);
        return tree;
    }
};
