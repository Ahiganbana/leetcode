#include <iostream>
#include <vector>
#include <<algorithm>
using namespace std;

  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    vector<int> result;
    TreeNode* tree;
public:
    //O(n) 空间复杂度 : 先将二叉树遍历存入数组中,然后重新构建
    void recoverTree(TreeNode* root) {
        //中序遍历
        midOrder(root);
        //排序
        sort(result.begin(),result.end());
        //重构二叉树
        root = buildTree(root);
    }

    //中序遍历得到所有的节点值
     void midOrder(TreeNode* root) {
        if(!root) {
            return;
        }
        midOrder(root->left);
        result.push_back(root->val);
        midOrder(root->right);
    }

    TreeNode* buildTree(TreeNode* root) {
        if(!root){
            return ;
        }
        int mid = findMid(root);
        tree = TreeNode(result[mid]);
        tree->left = buildTree(root->left);
        tree->right = buildTree(tree->right);
        return tree;
    }

    int findMid(TreeNode* root) {
        int mid = 0;
        for(int i = 0; i < result.size(); i++) {
            if(result[i] == root->val){
                mid = i;
                break;
            }
        }
        return mid;
    }
};           