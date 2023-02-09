#include <iostream>
#include <vector>
using namespace std;

// 求数中最大的BST子树

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ReturnType {
    int maxVal;
    int minVal;
    bool isBST;
    int cnt;
    TreeNode *maxSubRoot;
    ReturnType(int ma, int mi, int is, int c, TreeNode *node):maxVal(ma), minVal(mi), isBST(is), cnt(c), maxSubRoot(node){}
};

ReturnType* process(TreeNode *node) {
    if(!node) {
        return nullptr;
    }

    ReturnType *leftInfo = process(node->left);
    ReturnType *rightInfo = process(node->right);

    int minValue = node->val;
    int maxValue = node->val;
    int maxBSTSize = 0;
    TreeNode *root = nullptr;

    if(leftInfo) {
        minValue = min(minValue, leftInfo->minVal);
        maxValue = max(maxValue, leftInfo->maxVal);
    }

    if(rightInfo) {
        minValue = min(minValue, rightInfo->minVal);
        maxValue = max(maxValue, rightInfo->maxVal);
    }


    // 可能性1, 2 : 头节点不参与最大BST子树的计算,即最大BST子树出现在左右两个子树中
    if(leftInfo) {
        maxBSTSize = leftInfo->cnt;
        root = leftInfo->maxSubRoot;
    }

    if(rightInfo && rightInfo->cnt > maxBSTSize) {
        maxBSTSize = rightInfo->cnt;
        root = rightInfo->maxSubRoot;
    }

    bool isBST = false;

    // 可能性3 : 头节点参与bst子树的计算
    // 左右子树是BST
    if((!leftInfo || leftInfo->isBST) && (!rightInfo || rightInfo->isBST)) {
        // 并且满足头节点的值大于左子树的最大值 小于右子树的最小值 说明连根一起整棵子树是BST
        if((!leftInfo || leftInfo->maxVal < node->val) && (!rightInfo || rightInfo->minVal > node->val)) {
            isBST = true;
            int leftSize = leftInfo ? leftInfo->cnt : 0;
            int rightSize = rightInfo ? rightInfo->cnt : 0;
            maxBSTSize = rightSize + leftSize + 1;
            root = node;
        }
    }

    return new ReturnType(maxValue, minValue, isBST, maxBSTSize, root);
}