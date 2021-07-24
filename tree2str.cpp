#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t) { 
            return "";
        }
        if (!t->left && !t->right)
            return t->val + '0';
        
        if (!t->right)
            return  t->val + '0' + "(" + tree2str(t->left) + ")";
        return t->val + '0' + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};