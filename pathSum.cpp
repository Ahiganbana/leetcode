#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if(!root) {
            return 0;
        }
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return count;
    }

    void findNum(TreeNode* root, int sum) {
        if(!root) {
            return ;
        }
        sum = sum - root->val;
        if(sum == 0) {
            count++;
        }
        findNum(root->left, sum);
        findNum(root->right, sum);
    }    
};