#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//给一个二叉树找到其兄弟节点
class Solution {
    queue<Node*> q;
    Node *prev;
    Node *leftmost;

public:
    //层次遍历[空间复杂度为O(n)]
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *t = q.front();
                q.pop();
                if(i < size - 1) {
                    t->next = q.front();
                }
                if(t->left){
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
        }
        return root;
    }

    //不使用额外的空间
    Node* connect1(Node* root) {
        if(!root) {
            return root;
        }
        leftmost = root;
        Node *curr = leftmost;
        while(leftmost) {
            prev = nullptr;
            curr = leftmost;
            leftmost = nullptr;
            while(curr) {
                processChildNode(curr->left);
                processChildNode(curr->right);
                curr = curr->next;
            }
        }
        return root;
    }

    void processChildNode(Node* childNode) {
        if(childNode) {
            if(prev) {
                prev->next = childNode;
            }
            else{
                //初始化情况
                leftmost = childNode;
            }
            prev = childNode;
        }
    }
};