#include <iostream>
#include <vector>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    //二叉树的前序遍历(根左右)
    void flatten(TreeNode* root) {
        vector<TreeNode *> node;
        preorder(root, node);
        int size = node.size();
        for (int i = 1; i < size; i++) {
            TreeNode *prev = node.at(i - 1), curr = node.at(i);
            prev->left = nullptr_t;
            prev->right = curr;
        }
    }

    void preorder(TreeNode* root, vector<TreeNode*> &node) {
        if(root) {
            node.push_back(root);
            preorder(root->left, node);
            preorder(root->right, node);
        }
    }
};