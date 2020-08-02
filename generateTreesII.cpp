#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * 
 * */

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
    vector<TreeNode*> generateTrees(int n) {
        if(!n) {
            return {};
        }
        generateTrees(1, n);
    }

    vector<TreeNode*> generatorTrees(int start, int end) {
        if(start > end) {
            return nullptr;
        }
        vector<TreeNode*> allTrees;

        //选取合适的根节点
        for (int i = start; i <= end; i++) {
            //所有的左子树
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            //所有的右子树
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            for(auto& leftTree : leftTrees) {
                for(auto& rightTree : rightTrees) {
                    //创建当前根节点
                    TreeNode *root = TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    allTrees.emplace_back(root);
                }
            }
        }
        return allTrees;
    }
};
 