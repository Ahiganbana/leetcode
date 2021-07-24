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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) {
            return NULL;
        }

        if(root->val == val) {
            return root;
        }

        if(root->val < val && !root->right) {
            searchBST(root->right, val);
        }
        if(root->val > val && !root->left) {
            searchBST(root->left, val);
        }
    }
};