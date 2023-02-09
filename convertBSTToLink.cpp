#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ReturnType {
    Node *start;
    Node *end;

    ReturnType(Node *s, Node *e) : start(s), end(e){}
};


// 在返回的过程中 左右节点向父节点返回自己的子树组成的双向链表头和尾
ReturnType process(TreeNode *node) {
    if(!node) {
        return {nullptr, nullptr};
    }
    ReturnType left = process(node->left);
    ReturnType right = process(node->right);
    if(!left.end) {
        left.end->right = node;
    }
    node->left = left.end;
    node->right = right.start;

    if(!right.start) {
        right.start->left = node;
    }

    return {!left.start ? nullptr : left.start, !right.end ? nullptr : right.end};
}

TreeNode *convert(TreeNode *node) {
    if(!node) {
        return nullptr;
    }
    return process(node).start;
}