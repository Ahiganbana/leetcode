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
     int tilt = 0;

 public:
     int findTilt(TreeNode *root)
     {
         if (!root)
         {
             return 0;
         }
         return tilt;
    }

    int sum(TreeNode* root) {
        if(!root->left && !root->right) {
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);
        tilt += abs(left - right);
        return right + left + root->val;
    }
};