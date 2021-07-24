#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> result;
    stack<TreeNode*> s;

    //使用栈实现非递归的二叉树的中序遍历
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        while(!s.empty() || curr) {
           while(curr) {
               s.push(curr);
               curr = curr->left;
           }
           curr = s.top();
           s.pop();
           result.push_back(curr->val);
           curr = curr->right;
        }
        return result;
    }
};