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
    vector<int> vals;
    int minDiff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root){
            return minDiff;
        }
         if(root->left) {
            getMinimumDifference(root->left);
        }

        vals.push_back(root->val);
        if(vals.size() >= 2 && (vals[vals.size() - 1] - vals[vals.size() - 2]) < minDiff) {
            minDiff = vals[vals.size() - 1] - vals[vals.size() - 2];
        }

        if(root->right) {
            getMinimumDifference(root->right);
        }

        return minDiff;
    }
};