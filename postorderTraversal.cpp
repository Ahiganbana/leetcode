#include <iostream>
#include <stack>
#include <vector>
#include <map>
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return result;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode *t = s.top();
            result.insert(v.begin(), t->val);
            if(t->left) {
                s.push(t->left);
            }
            if(t->right) {
                s.push(t->right);
            }
        }
        return result;
    }
};