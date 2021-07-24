#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//计算从根节点到叶子节点的数字之和
class Solution {
    vector<vector<int>> result;
    int resultSum;

public:
    int sumNumbers(TreeNode* root) {
        vector<int> path;
        findPaths(root, path);
        int levels = result.size();
        int len = 0;
        int sumNum = 0;
        for (int i = 0; i < levels; ++i) {
            //每条路的长度
            len = result[i].size();
            for (int j = 0; j < len; ++j) {
                sumNum += result[i][j] * pow(10, len - 1 - i);
            }
        }
        return sumNum;
    }

    //找到树中所有从跟到叶子的路
    void findPaths(TreeNode* root,vector<int>& path) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right) {
            result.push_back(path);
        }
        findPaths(root->left, path);
        findPaths(root->right, path);
        path.pop_back();
    }
    //不额外维护数组,直接在遍历的时候计算
    void findPaths(TreeNode* root, int val) {
        if(!root) {
            return;
        }
        int tmp = 10 * val + root->val;
        if(!root->left && !root->right) {
            resultSum += tmp;
        }
        if(root->left) {
            findPaths(root->left, tmp);
        }
        if(root->right) {
            findPaths(root->right, tmp);
        }
    }
};