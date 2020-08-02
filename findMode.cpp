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
    int maxCount = 1;
    int tmp = 1;
    int curr = INT_MIN;
    vector<int> result;

    vector<int> findMode(TreeNode* root) {
        if(!root) {
            return result;
        }
        if(root->left) {
            findMode(root->left);
        }
        if(curr == root->val) {
            tmp++;
            if(tmp == maxCount) {
                result.push_back(curr);
            }
            else if (tmp > maxCount){
                maxCount = tmp;
                result.clear();
                result.push_back(curr);
            }
        }
        else{
            tmp = 1;
        }

        curr = root->val;
        if(maxCount == 1){
            result.push_back(curr);
        }

        if(root->right) {
            findMode(root->right);
        }

        return result;
    }
};