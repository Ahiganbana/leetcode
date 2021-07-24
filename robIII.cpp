#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //将二叉树上的每个节点和节点上的值做映射
    unordered_map<TreeNode *, int> f, g;

public:
    /**
     * 采用动态规划的思路,后序遍历整棵树,分为两种情况:
     * 1.选择根节点的情况下,最大的权值应该为使左右子树分别作为根不选择根节点时左右两个子树的和
     * 2.不选择根节点的情况下,最大的权值应该为选择左子树/右子树的根的情况下两者的最大值
     * */
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }

    //使用后序遍历
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }
};
