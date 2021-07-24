#include <iostream>
#include <queue>
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
    queue<TreeNode *> q;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return result;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            result.push_back(level);
        }
        return result;
    }
};