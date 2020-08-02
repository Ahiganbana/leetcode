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
private :
    TreeNode *tree = new TreeNode(0);
    TreeNode *tree1 = tree;

    void dlr(TreeNode* root) {
        if(root != NULL){
            dlr(root->left);
            visit(root);
            dlr(root->right);
        }
    }

    void visit(TreeNode* root) {
        root->left = NULL;
        tree->right = root;
        tree = root;
    }

public:
    TreeNode* convertBiNode(TreeNode* root) {
        dlr(root);
        return tree1->right;
    }
};