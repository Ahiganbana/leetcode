#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    stack<TreeNode *> s;
    vector<int> result;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return result;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode *t = s.top();
            s.pop();
            result.push_back(t->val);
            if(t->right) {
                s.push(t->right);
            }
            if(t->left) {
                s.push(t->left);
            }
        }
        return result;
    }
};