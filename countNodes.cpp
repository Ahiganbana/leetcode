#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//计算完全二叉树的节点个数
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lDepth = getDepth(root->left);
        int rDepth = getDepth(root->right);
        if(lDepth == rDepth) {
            //说明左子树是满二叉树
            return pow(2, lDepth) + countNodes(root->right);
        }else{
            return pow(2, rDepth) + countNodes(root->left);
        }
    }

    //计算树深度
    int getDepth(TreeNode* root) {
        int depth = 0;
        while(root) {
            depth++;
            root = root->left;
        }
        return depth;
    }
};