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

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        //构造哈希映射
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildSubTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if(preorder_left > preorder_right) {
            return nullptr;
        }

        //在前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        //在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_left]];
        
        //建立根节点
        TreeNode *tree = new TreeNode(preorder[preorder_left]);

        //左子树数目
        int size_left_subtree = inorder_root - inorder_left;
        tree->left = buildSubTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree,inorder_left, inorder_root - 1);
        tree->right = buildSubTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return tree;
    }
};