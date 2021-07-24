#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//多叉树的层次遍历

class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return res;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *tmp = q.front();
                q.pop();
                Node *ctmp = tmp->children;
                level.emplace_back(tmp->val);
                if(ctmp) {
                    for (int j = 0; j < tmp->children.size(); ++j) {
                        q.push(tmp->children[i]);
                    }
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};