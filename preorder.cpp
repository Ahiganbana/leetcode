#include <iostream>
#include <vector>
#include <stack>
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

//N叉树的前序遍历 (根左右)
class Solution {
    vector<int> result;

public:
    //递归遍历
    vector<int> preorder(Node* root) {
        if(root) {
            result.push_back(root->val);
            int size = root->children.size();
            if(size != 0){
                for (int i = 0; i < size; i++) {
                    preorder(root->children[i]);
                }
            }
        }
        return result;
    }

    //非递归遍历,将N叉树的每个节点倒序入栈
    vector<int> preorder(Node* root) {
        stack<Node *> s;
        s.push(root);
        while(!s.empty()) {
            Node *t = s.top();
            s.pop();
            if(t) {
                result.emplace_back(t->val);
            }else{
                continue;
            }
            
            if(!t->children.empty()) {
                int size = t->children.size();
                for (int i = size - 1; i > 0; --i) {
                    if(t->children[i]) {
                        s.push(t->children[i]);
                    }
                }
            }
        }
        return result;
    }
};