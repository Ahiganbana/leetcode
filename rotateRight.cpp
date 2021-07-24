#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//旋转链表, 将每个节点向右移动k个位置
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *second = dummy;
        ListNode *first = head;
        int count = 0;
        while(first){
            count++;
            first = first->next;
        }
        if(!head || k % count == 0){
            return head;
        }
        first = head;
        for (int i = 0; i < k % count; i++) {
            first = first->next;
        }
        while(first){
            cout << first->val;
            second = second->next;
            if(first->next){
                first = first->next;
            }else{
                break;
            }
        }
        head = second->next;
        second->next = nullptr;
        first->next = dummy->next;
        delete dummy;
        return head;
    }
};
