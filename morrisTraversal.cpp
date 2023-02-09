//  树的Morris遍历
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 void morris(TreeNode *head) {
     TreeNode *cur = head;
     TreeNode *ptr = head;
     while(cur) {
         if(cur->left) {
             ptr = cur->left;
             while(ptr->right && ptr->right != cur) {
                 // 找到cur左子树上最右的指针
                 ptr = ptr->right;
             }
             if(!ptr->right) {
                 ptr->right = cur;
                 cur = cur->left;
                 continue;
             }
             if(ptr->right == cur) {
                 ptr->right = nullptr;
             }
         }
         cur = cur->right;
     }
 }

 // 基于Morris的先序遍历
 void preOrder(TreeNode *head) {
     TreeNode *cur = head;
     TreeNode *ptr = nullptr;
     while(cur) {
         ptr = head->left;
         if(ptr) {
             //有左子树
             while(ptr->right && ptr->right != cur) {
                 ptr = ptr->right;
             }
             if(!ptr->right) {
                 cout << cur->val;
                 ptr->right = cur;
                 cur = cur->left;
                 continue;
             }
             else {
                 ptr->right = null;
             }
         }
         else {
             // 没有左子树
             cout << cur->val;
         }
         cur = cur->right;
     }
 }

// 基于Morris的中序遍历
void inOrder(TreeNode *head) {
    TreeNode *cur = head;
    TreeNode *ptr = nullptr;
    while(cur) {
        ptr = head->left;
        if(ptr) {
            //有左子树
            while(ptr->right && ptr->right != cur) {
                ptr = ptr->right;
            }
            if(!ptr->right) {
                ptr->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                ptr->right = null;
            }
        }
        cout << cur->val;
        cur = cur->right;
    }
 }

 // 基于Morris的后序遍历
 void inOrder(TreeNode *head) {
    TreeNode *cur = head;
    TreeNode *ptr = nullptr;
    while(cur) {
        ptr = head->left;
        if(ptr) {
            //有左子树
            while(ptr->right && ptr->right != cur) {
                ptr = ptr->right;
            }
            if(!ptr->right) {
                ptr->right = cur;
                cur = cur->left;
                continue;
            }
            else {
                ptr->right = null;
                printEdge(cur->left);
            }
        }
        cur = cur->right;
    }
    printEdge(head);
 }

 TreeNode *reverseEdge(TreeNode *from) {
     TreeNode *pre = nullptr;
     TreeNode *next = nullptr;

     while(from) {
         next = from->right;
         from->right = pre;
         pre = from;
         from = next;
     }
     return pre;
 }

 // 利用Morris判断一棵树是否是搜索二叉树
 bool isBST(TreeNode *head)
 {
     TreeNode *cur = head;
     TreeNode *ptr = nullptr;
     int preValue = INT_MIN;
     while (cur)
     {
         ptr = head->left;
         if (ptr)
         {
             //有左子树
             while (ptr->right && ptr->right != cur)
             {
                 ptr = ptr->right;
             }
             if (!ptr->right)
             {
                 ptr->right = cur;
                 cur = cur->left;
                 continue;
             }
             else
             {
                 ptr->right = null;
             }
         }
         if(cur->val <= preValue) {
             return false;
         }
         preValue = cur->val;
         cur = cur->right;
     }
     return ture;
 }