#include <iostream>
#include <vector>
#include <algorthm>
#include <unordered_map>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//根据中序和后序遍历创建二叉树
class Solution {
    unordered_map<int> index;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return subBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* subBuildTree(vector<int>& inorder, vector<int>& postorder, int postorder_left, int postorder_right, int inorder_left, int inorder_right){
        if(postorder_left > postorder_right) {
            return nullptr;
        }

        //后序遍历中的最后一个节点为根节点
        int postorder_root = postorder_right;
        //在中序遍历中找到根节点
        int inorder_root = index[postorder[postorder_right]];
        //建立根节点
        TreeNode *tree = new TreeNode(postorder[postorder_right]);

        //计算左子树的个数
        int size_sub_tree = inorder_root - inorder_left;
        tree->right = subBuildTree(inorder, postorder, postorder_left + size_sub_tree, postorder_right - 1, inorder_root + 1, inorder_right);
        tree->left = subBuildTree(inorder, postorder, postorder_left, postorder_left + size_sub_tree - 1, inorder_left, inorder_root - 1);
        return tree;
    }
};