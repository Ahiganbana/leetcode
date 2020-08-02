#include <iostream>
#include <vector>
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
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }

    bool helper(TreeNode* s,TreeNode* t) {
        //判断两棵树是否相等
        if(!s && !t){
            return true;
        }
        if ((!s && t) || (s && !t) || (s->val != t->val){
            return false;
        }
        return helper(s->left, t->left) && helper(s->right, t->right);
    }

    //深度遍历一次判断子树
    bool dfs(TreeNode* s,TreeNode* t) {
        if(!s) {
            return false;
        }
        return helper(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }
};