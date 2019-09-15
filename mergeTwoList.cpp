#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public : 
//1. 迭代实现
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 != NULL ? l1 : l2;
        return head->next;
    }
};

int main(){
    ListNode *list1;
    ListNode *list2;
    
    system("pause");
    return 0;
}