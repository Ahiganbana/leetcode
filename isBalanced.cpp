#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int  calculateTreeHight(TreeNode* tree) {
        if(!tree){
            return -1;
        }else{
            return max(calculateTreeHight(tree->left), calculateTreeHight(tree->right)) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        return (abs(calculateTreeHight(root->left) - calculateTreeHight(root->right)))< 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};