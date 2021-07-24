// 判断一个链表是否为回文结构
#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) {
            return true;
        }
        if (!head->next->next) {
            return head->val == head->next->val;
        }
        // 找到链表中点
        ListNode *mid = head ;
        ListNode *fast = head ;
   
        while(fast->next && fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }

        stack<int> s;
        ListNode *ptr = head;
        while(ptr != mid) {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        int midVal = mid->val;
        while(!s.empty() && mid) {
            if(s.top() == mid->val) {
                s.pop();
                mid = mid->next;
            }else {
                if(mid->val != midVal) {
                    return false;
                }
                mid = mid->next;
            }
        }
        return s.empty() && !mid;
    }

    bool isPalindrome(ListNode *head) {
        if(!head || !head -> next) {
            return true;
        }
        if (!head->next->next) {
            return head->val == head->next->val;
        }
        // 找到链表中点
        ListNode *mid = head ;
        ListNode *fast = head ;
   
        while(fast->next && fast->next->next) {
            mid = mid->next;
            fast = fast->next->next;
        }

        // 反转中点之后的链表
        ListNode *newHead = mid;
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while(newHead->next) {
            next = newHead->next;
            newHead->next = pre;
            pre = newHead;
            newHead = next;
        }
        newHead->next = nullptr;

        ListNode *p1 = head;
        ListNode *p2 = newHead;
        while(p1 && p2) {
            if(p1->val == p2->val) {
                p1 = p1->next;
                p2 = p2->next;
            }else {
                return false;
            }
        }
        return true;
    }
};