// 树形dp 
/*
    根节点希望从左,右子树得到的信息有:
    1. 左子树覆盖需要的监控数量
    2. 右子树覆盖需要的监控数量
    每个节点可以选择安装监控或者不安装监控
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Status{
    // 根节点必须装摄像头 需要的摄像头的数量
    //a = lc + rc + 1
    int a;
    // 根节点选择不装摄像头, 需要的摄像头数量
    // b = min(a, min(la + rb, ra + lb))
    int b;
    // 覆盖两个子树需要的摄像头数量
    int c;
}

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }

    Status dfs(TreeNode* root) {
        if(!root) {
            return {-1, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }
};