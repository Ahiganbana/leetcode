#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//删除链表的倒数第n个节点,返回列表的头结点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *emptyNode = new ListNode(0, head);
        ListNode *first = emptyNode;
        ListNode *second = emptyNode;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *ans = emptyNode->next;
        delete emptyNode;
        return ans;
    }
};