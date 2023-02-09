// 判断一棵树是否为完全二叉树
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层次遍历
/**
 * 1. 任意节点又有孩子但是没有左孩子 返回false
 * 2. 在 1 的条件下, 如果遇到了第一个左右两个孩子不全的情况 那么所有节点都是叶子节点
 * */
     bool isComleteBinaryTree(TreeNode *head) {
     if(!head){
         return true;
     }
     queue<TreeNode *> q;
     q.push(head);
     while(!q.empty()) {
         TreeNode *treeNode = q.front();
         q.pop();
         if(treeNode->left && treeNode->right) {
             q.push(treeNode->left);
             q.push(treeNode->right);
         }else if(!treeNode->left && treeNode->right) {
             return false;
         }else if((treeNode->left && !treeNode->right) || (!treeNode->left && !treeNode->right)) {
             if(treeNode->left)
                 q.push(treeNode->left);
             while(!q.empty()) {
                 TreeNode *tmpNode = q.front();
                 q.pop();
                 if(tmpNode->left || tmpNode->right) {
                     return false;
                 }
             }
         }
     }
     return true;
 }