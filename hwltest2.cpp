#include <iostream>
using namespace std;

struct Node {
    Node *pNext;
    int nValue;
    Node(int v) : pNext(nullptr), nValue(v){}
};

Node* Reserve(Node* pList) {
    Node * node = pList;
    while(pList && node->pNext) {
        Node* tmp = node->pNext;
        node->pNext = node->pNext->pNext;
        tmp->pNext = pList;
        pList = tmp;
    }
    return pList;
}

int main() {
    int list[5] = {1, 2, 3, 4, 5};
    Node *pList = new Node(-1);
    Node *head = pList;
    for(int i = 0; i < 5; ++i) {
        Node *node = new Node(list[i]);
        pList->pNext = node;
        pList = node;
    }
    
    Node *rpList = Reserve(head);
    Node *tmp = rpList;
    while(tmp) {
        cout << tmp->nValue << " ";
        tmp = tmp->pNext;
    }
    system("pause");
    return 0;
}