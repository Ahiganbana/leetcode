#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution {
    int max_depth;

public:
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }else if(root->children.size() == 0){
            return 1;
        }else {
            int child_sum = root->children.size();
            vector<int> child_depth(child_sum, 0);
            for (int i = 0; i < child_sum; i++) {
            int depth = max_depth(root->children[i]);
            child_depth.push_back(depth);
        }
        return (*(max_element(child_depth.begin(), child_depth.end()))) + 1;
        }
    }
};