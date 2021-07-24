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

//给定完美二叉树,找到每个节点的兄弟
class Solution {
    queue<Node *> q;

public:
    //层次遍历,借助队列实现
    Node* connect(Node* root) {
        if(!root) {
            return nullptr;
        }
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *t = q.front();
                q.pop();
                if(i < size - 1) {
                    t->next = q.front();
                }
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
        }
        return root;
    }

    //不适用额外的空间,采用next指针建立连接
    Node* connect1(Node* root) {
        Node *tree = root;
        while(tree->left) {
            Node *head = tree;

            while(head) {
                head->left->next = head->right;
                if(head->next) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            tree = tree->left;
        }
        return root;
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int t = 0;
    while(!q.empty()){
        t = q.front();
        q.pop();
        cout << "t = " << t << endl;
        cout << "q.front() = " << q.front() << endl;
    }
    system("pause");
    return 0;
}