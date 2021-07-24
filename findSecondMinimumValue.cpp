#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
   //priority_queue<int, vector<int>, greater<int>> q;
   vector<int> result;

   public:
   int findSecondMinimumValue(TreeNode *root)
   {
       if (!root)
       {
           return -1;
       }
       preOrder(root);
       int size = result.size();
       int num = -1;
       if(size != 0) {
           int t = result[0];
           sort(result.begin(), result.end());
           int i = 1;
           while(i < size) {
               if(t == result[i]) {
                   ++i;
               }else {
                   t = result[i];
                   num = t;
                   break;
               }
           }
       }
       return num;
    }

    void preOrder(TreeNode *root) {
        if(!root) {
            return;
        }
        result.emplace(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};
