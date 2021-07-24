#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// Definition for a Node
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

//N叉树的后序遍历
class Solution {
    vector<int> result;
    stack<Node *> s;


public:
    //非递归解法
    vector<int> postorder(Node* root) {
        s.push(root);
        while(!s.empty()) {
            Node *t = s.top();
            s.pop();
            if(t) {
                 result.push_back(t->val);
            }
            int size = t->children.size();
            if(size != 0) {
                for (int i = 0; i <size; i++) {
                    s.push(t->children[i]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    //递归解法
     vector<int> postorder1(Node* root) {
        if(root) {
            int size = root->children.size();
            if(size != 0) {
                for(int i=0; i<size; i++) {
                    postorder1(root->children[i]);
                }
            }
            result.push_back(root->val);
        }
        return result;
    }
};