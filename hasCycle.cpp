// 判断链表是否有环
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast->next && fast->next->next && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(!fast->next || !fast->next->next) {
            return false;
        }
        return true;
    }
};