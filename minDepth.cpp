#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->right && !root->left) {
            return 1;
        }
        int min_depth = INT_MAX;
        if(root->left) {
            min_depth = min(min_depth, minDepth(root->left));
        }
        if(root->right) {
            min_depth = min(min_depth, minDepth(root->right));
        }
        return min_depth + 1;
    }
};