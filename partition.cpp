#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//对链表进行分割,使得所有小于x的值出现在大于等于x的节点之前
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = new ListNode();
        ListNode *largeHead = new ListNode();
        ListNode *ptr = head;
        ListNode *small = smallHead;
        ListNode *large = largeHead;
        while(ptr) {
            ListNode *node = new ListNode(ptr->val);
            if(ptr->val >= x){
                large->next = node;
                large = large->next;
            }else{
                small->next = node;
                small = small->next;
            }
            ptr = ptr->next;
        }
        small->next = largeHead->next;
        ptr = smallHead->next;
        delete smallHead;
        delete largeHead;
        return ptr;
    }
};
