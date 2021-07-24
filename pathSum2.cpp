//找到二叉树中所有从根节点到叶子节点和值为给定值的路径
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
    vector<vector<int>> result;

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) {
            return result;
        }
        vector<int> path;
        findPath(root,sum,path);
        return result;
    }

    void findPath(TreeNode* root, int sum, vector<int>& path) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        sum = sum - root->val;
        //到叶子节点
        if(!root->left && !root->right) {
            //到叶子节点且值为0
            if(sum == 0) {
                 result.push_back(path);
            }
        }
        findPath(root->left, sum, path);
        findPath(root->right, sum, path);
        path.pop_back();
    }
};