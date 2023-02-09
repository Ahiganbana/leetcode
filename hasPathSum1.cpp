
// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return process(root, targetSum);
    }

    bool process(TreeNode* root, int targetSum, int curr)  {
        if(root && targetSum < root->val) {
            return false;
        }
        if(!root->left && !root->right) {
            if(root->val == target) {
                return true;
            }else {
                return false;
            }
        }

        return process(root->left, targetSum - root->val) || process(root->right, targetSum - root->val);
    }
};