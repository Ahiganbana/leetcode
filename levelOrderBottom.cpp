#include <iostream>
#include <queue>
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) {
            return;
        }
        queue<TreeNode*> queue;
        vector<vector<int>> result;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *t = queue.front();
                queue.pop();
                level.push_back(t->val);
                if(t->left){
                    queue.push(t->left);
                }
                if(t->right) {
                    queqe.push(t->right);
                }
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};