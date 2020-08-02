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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBST(root, sum);
        return root;
    }

    void convertBST(TreeNode* root, int &sum) {
        if(!root) {
            return ;
        }

        convertBST(root->right, sum);
        sum += root->val;
        root->val = sum;
        convertBST(root->left, sum);
    }
};