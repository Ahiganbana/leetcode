// 判断一棵树是否是满二叉树
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct SubInfo {
    int height;
    int nodeSize;
    SubInfo(int h, int s) : height(h), nodeSize(s){}
} 

SubInfo *process(TreeNode *tree) {
    if(!tree) {
        SubInfo *info = new SubInfo(0, 0);
        return info;
    }

    SubInfo *leftSubInfo = process(tree->left);
    SubInfo *rightSubInfo = process(tree->right);

    int height = max(leftSubInfo->height, rightSubInfo->height) + 1;
    int nodeSize = leftSubInfo->nodeSize + rightSubInfo->nodeSize + 1;

    SubInfo *newInfo = new (height, nodeSize);
    return newInfo;
}

// 需要从子树上拿到的信息 : 子树的高度 子树的节点个数
bool isFullBinaryTree(TreeNode *tree) {
    if(!tree) {
        return true;
    }
    SubInfo *data = process(tree);
    return data->nodeSize == 1 << data->height - 1;
} 