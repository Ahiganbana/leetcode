#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return head;
        }
        Node* newNode = new Node(-1);
        Node* p = newNode;
        Node* temp = head;
        while(temp != nullptr) {
            //为链表的每一个节点复制一个节点并添加在原节点后面
            //此时节点的random指向原节点的random
            Node* node = new Node(temp->val);
            node->next = temp->next;
            node->random = temp->random;
            temp->next = node;
            temp = node->next;
        }
        Node* temp1 = head, *temp2 = head->next;
        //重新设置复制节点的random域
        while(temp1 != nullptr) {
            if(temp1->random == nullptr) {
                temp2->random = nullptr;
            }else{
                temp2->random = temp1->random->next;
            }
            p->next = temp2;
            p = p->next;
            temp1->next = temp2->next;
            if(temp2->next != nullptr) {
                temp1 = temp2->next;
                temp2 = temp1->next;
            }else{
                break;
            }
        }
        printList(newNode->next);
        return newNode->next;
    }

    void printList(Node* head) {
        Node *temp = head;
        while(temp) {
            cout << temp->val << "->" << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Solution solution;
    int n = 0, val = 0;
    cin >> n;
    Node *head = new Node(0);
    Node *temp = head;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        Node *node = new Node(val);
        node->next = temp->next;
        temp->next = node;
        temp = temp->next;
    }
    solution.copyRandomList(head);
    system("pause");
    return 0;
}