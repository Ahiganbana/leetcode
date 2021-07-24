#include <iostream>
using namespace std;

// 将链表按照某个值划分为 左边比他小 中间和他相等 右边比他大的结构
// 保留原有数字的顺序
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *liatPartition(ListNode *head, int pivot) {
    ListNode *sHead = nullptr;
    ListNode *sTail = nullptr;
    ListNode *eHead = nullptr;
    ListNode *eTail = nullptr;
    ListNode *mHead = nullptr;
    ListNode *mTail = nullptr;
    ListNode *next = nullptr;
    while(head) {
        next = head->next;
        head->next = nullptr;
        if(head->val < pivot) {
            if(!sHead) {
                sHead = head;
                sTail = head;
            }else {
                sTail->next = head;
                sTail = head;
            }
        }else if(head->val == pivot) {
            if(!eHead) {
                eHead = head;
                eTail = head;
            }else {
                eTail->next = head;
                eTail = head;
            }
        }else {
            if(!mHead) {
                mHead = head;
                mTail = head;
            }else {
                mTail->next = head;
                mTail = head;
            }
        }

        // 讨论是否有大于/小于/等于区域
        if(sTail) {
            sTail->next = eHead;
            eTail = !eTail ? sTail : eTail;
        }

        if(eTail) {
            eTail->next = mHead;
        }

        return sHead ? sHead : (eHead ? eHead : mHead);
    }
}