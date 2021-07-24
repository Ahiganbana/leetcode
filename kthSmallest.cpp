#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left. TreeNode *right) : val(x), left(left), right(right){}
};

//找出二叉搜索树中第K小的数
class Solution {
    vector<int> result;

public:
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);
        return result[k - 1];
    }

    //中序遍历
    void inorderTraversal(TreeNode* root) {
        if(!root) {
            return;
        }
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        while(true) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(--k == 0) {
                return root->val;
            }
            root = root->right;
        }
    }
};