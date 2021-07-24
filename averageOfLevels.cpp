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
    vector<double> result;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //对树进行层次遍历后求平均值
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
            result.push_back(average(level));
        }
        return result;
    }

    double average(vector<int>& level) {
        double size = level.size();
        double sum = 0;
        for(int i = 0; i< size; ++i) {
            sum += level[i];
        }
        return sum / size;
    }
};   