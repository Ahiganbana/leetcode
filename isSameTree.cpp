#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&& !q) {
            return true;
        }
        if(p->val != q->val) {
            return false;
        }
        if(!p||!q) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};