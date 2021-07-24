#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    vector<vector<int>> result;
    queue<TreeNode*> q;

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return result;
        }
        int flag = 0;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            result.push_back(level);
        }
        for(int i = 0; i < result.size(); i++) {
            if(i % 2 == 1) {
                reverse(result[i].begin(),result[i].end());
            }
        }
        return result;
    }
};

int main(){
    char chr = 127;
    int sum = 200;
    chr += 1;
    sum += chr;
    cout << sum;
    system("pause");
    return 0;
}