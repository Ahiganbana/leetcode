#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution{
    Node *res;

public: 
    Node *flatten(Node* head) {
        if(!head) {
            return head;
        }
        //buildLink(head);
        return buildLink(head);
    }
    Node* buildLink(Node *head) {
        res = head;
        while(head) {
            Node *pnext = head->next;
            Node *pchild = head->child;
            if(pchild) {
                head->child = nullptr;
                head->next = pchild;
                pchild->prev = head;
                Node *temp = dfs(pchild);
                if(pnext) {
                    temp->next = pnext;
                    pnext->prev = temp;
                }
            }
            head = pnext;
            if(head) {
                res = head;
            }
        }
        return res;
    }
}