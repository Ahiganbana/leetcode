#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    vector<int> result;
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int size = result.size();
        for(int i = 0; i < size(); i++) { 
            for(int j = i + 1; j < size(); j++) { 
                if(result[i] + result[j] == k) { 
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(TreeNode* root) {
        if(!root) { 
            return;
        }
        result.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};