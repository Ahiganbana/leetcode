#include <iostream>
#include <cmath>
using namespace std;

// 判断一棵树是否为平衡二叉树
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct ReturnType{
     bool isBalance;
     int height;
     ReturnType(bool ib, int h) : isBalance(ib), height(h){}
 };

class Solution {
public:
    int  calculateTreeHight(TreeNode* tree) {
        if(!tree){
            return -1;
        }else{
            return max(calculateTreeHight(tree->left), calculateTreeHight(tree->right)) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        return (abs(calculateTreeHight(root->left) - calculateTreeHight(root->right)))< 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    // 从左右子树想获得什么信息?
    /**
     * 想知道左右子树是否是平衡的以及其高度
     * */
    //  返回长度固定为2的数组 分别保存 子树是否是平衡的以及其高度
    ReturnType process(TreeNode *root) {
        if(!root) {
            ReturnType r = {true, 0};
            return r;
        }
        ReturnType leftData = process(root->left);
        ReturnType rightData = process(root->right);

        int height = max(leftData.height, rightData.height) + 1;
        bool isBalanced = leftData.isBalance && rightData.isBalance && abs(leftData.height - rightData.height) < 2;
        ReturnType finalReturn = {isBalanced, height};
        return finalReturn;
    }

    bool isBalanced(TreeNode *tree) {
        ReturnType r = process(tree);
        return r.isBalance;
    }
};