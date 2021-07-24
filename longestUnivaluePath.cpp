#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    /**
     * 找到树中具有相同值得节点组成得最长路径
     * */
    int result;

public:
    int longestUnivaluePath(TreeNode* root) {
        result = 0;
        depth(root);
        return result;
    }

    int depth(TreeNode *root) {
        if(!root) {
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        int left_count = 0, rigth_count = 0;
        if(root->left && root->left->val == root->val) {
            left_count = left + 1;
        }
        if(root->right && root->right->val == root->val) {
            rigth_count = right + 1;
        }

        result = max(result, left_count + rigth_count);
        return max(left_count, rigth_count);
    }
};

