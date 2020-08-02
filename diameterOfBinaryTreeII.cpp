#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//计算二叉树的最大直径,需要注意的点在于最大直径有可能不会穿过根节点
//需要依次计算每一个子树的最大深度,记录当前的最大直径.直径的计算方式可以写为左子树深度＋右子树深度+1
//(此时为单颗树的直径,需要遍历整棵树,以便于找到其中直径的最大值.)
class Solution {
    int max_diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 1;
        depth(root);
        return max_diameter - 1;
    }

    int depth(TreeNode* root){
        if(!root){
            return 0;
        }else{
            int left = depth(root->left);
            int right = depth(root->right);
            max_diameter = max(max_diameter, left + right + 1);
            return max(left, right) + 1;
        }
    }
};