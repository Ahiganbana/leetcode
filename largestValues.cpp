#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//在二叉树的每一行中找到最大的值
class Solution {
    vector<int> res;

public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int maxValue = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if(maxValue < tmp->val) {
                    maxValue = tmp->val;
                }
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.emplace_back(maxValue);
        }
        return res;
    }
};
