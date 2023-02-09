#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int mostLeftLevel(TreeNode *root, int level) {
    while(root) {
        level++;
        root = root->left;
    }
    return level - 1;
}

// level表示node在第几层 求以node为头的子树 最大深度是多少
int bs(TreeNode *node, int level, int h) {
    if(level == h) {
        return 1;
    }
    if(mostLeftLevel(node->right, level + 1) == h) {
        return (1 << (h - level - 1)) + bs(node->right, level + 1, h);
    }else {
        return (1 << (h - level - 1)) + bs(node->left, level + 1, h);
    }
}

// 求以head为头的完全二叉树的节点个数
int nodeNum(TreeNode *head) {
    if(!head) {
        return 0;
    }
    return bs(head, 1, mostLeftLevel(head, 1));
}