#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//判断一颗树是否为二叉搜索树
class Solution {
public:
     bool subIsValidBST(TreeNode* root, long long lower, long long upper) {
        if(root == nullptr) {
            return true;
        }
        if(root->val <= lower || root->val >= upper) {
            return false;
        }
        return subIsValidBST(root->left, lower, root->val) && subIsValidBST(root->right,root->val, upper);
    }

     bool isValidBST(TreeNode* root) {
        return subIsValidBST(root, LONG_MIN, LONG_MAX);
    }
};