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
     int max_diameter;

 public:
     int diameterOfBinaryTree(TreeNode *root){
         max_diameter = 1;
         depth(root);
         return max_diameter - 1;
     }

    int depth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        max_diameter = max(max_diameter, left + right + 1);
        return max(left, right) + 1;
    }
};