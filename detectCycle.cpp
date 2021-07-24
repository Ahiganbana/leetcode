#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//返回链表开始入环的第一个节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head;
        ListNode *second = head;
        while (first != nullptr){
            second = second->next;
            if(first->next == nullptr){
                return nullptr;
            }
            first = first->next->next;
            if(first == second){
                ListNode *ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    second = second->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast) {
            slow = slow->next;
            if(!fast->next) {
                return false;
            }
            fast = fast->next->next;
            if(fast == slow) {
                fast = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};