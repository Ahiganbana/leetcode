#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//返回右侧能看到的节点值
class Solution {
    queue<TreeNode *> q;
    vector<int> result;

public:
    vector<int> rightSideView(TreeNode* root) {
        //使用层次遍历的方式
        if(!root) {
            return result;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *t = q.front();
                q.pop();
                if(i == size - 1) {
                    result.push_back(t->val);
                }
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
        }
        return result;
    }
};