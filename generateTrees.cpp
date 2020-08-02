#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public :
/**
 * 动态规划练习
 * 生成二叉搜索树
 * 首先使用递归的思想来构建二叉树
 * 假设要构建的数为n 从1...n中取出任意一个数 i 以i为树根构建子树 此时,i-1个树构成了左子树,n-i个数构成了右子树
 * 此时会产生G(i-1)个左子树和G(n-i)个右子树 G为卡特兰数
 * 则找到递归的关系  明白构建过程中的递归关系后,开始实现动态规划
 * 1.确定存放历史数据的数组 对于以i为根的树 dp[i]中存放的为以i为根的树
 *   dp[i-1]中存放的是这棵树的左子树 dp[n-i]中存放的是这棵树的右子树
 * 2.确定转移方程
 * 3.确定初始值
 */
    //拷贝树的实现 在构造的过程中 后面的树的构造可以直接将前面的树复制过来
    TreeNode *copyTree(TreeNode *root, int delta = 0) {
        auto newroot = new TreeNode(root->val + delta);
        queue<TreeNode *> qtree;
        queue<TreeNode *> qnewtree;
        qtree.push(root);
        qnewtree.push(newroot);
        while(!qtree.empty()) {
            auto old_root = qtree.front();
            qtree.pop();
            auto new_root = qnewtree.front();
            qnewtree.pop();
            if(old_root->left) {
                new_root->left = new TreeNode(old_root->left->val + delta);
                qtree.push(old_root->left);
                qnewtree.push(new_root->left);
            }
            if(old_root->right) {
                new_root->right = new TreeNode(old_root->right->val + delta);
                qtree.push(old_root->right);
                qnewtree.push(new_root->right);
            }
        }
        return newroot;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode *>> dp(1, vector<TreeNode *>(1, NULL));
        int size = n + 1;
        int dsize = dp.size();
        if(size > dsize) {
            dp.resize(size);
        }
        if(n == 0){
            return {};
        }
        for (int i = dsize; i <= n; i++) {
            for (int j = 1; j <= i; j++) {//遍历不同的数为根
                auto const &left = dp[j - 1];
                auto const &right = dp[i - j];
                auto &cc = dp[i];
                for(const auto left_per : left) {
                    for(const auto right_per : right) {
                        auto root = new TreeNode(j);
                        if(j > 1) {
                            root->left = copyTree(left_per);
                        }
                        if(i > j) {
                            root->right = copyTree(right_per, j);
                        }
                        cc.push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    vector<TreeNode *> result;
    result = solution.generateTrees(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    system("pause");
    return 0;
}