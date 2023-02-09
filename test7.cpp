#inculde<vector>
struct ListNode {
    int value;
    int *next;
}

ListNode *listProcess(ListNode *list1, ListNode *list2, int n, int m) {
    ListNode *tmp1 = list1;
    ListNode *tmp2 = list1;
    int count1 = 1, count2 = 1;
    while(count1 < n && tmp1) {
        tmp1 = tmp1->next;
        count1++;
    }
    while(count2 < m && tmp2) {
        tmp2 = tmp2->next;
        count2++;
    }

    ListNode *tmp3 = list1;
    while(tmp3 != tmp1) {
        tmp3 = tmp3->next;
    }
    tmp3->next = list2;
    ListNode *tmp4 = list2;
    while(tmp4->next) {
        tmp4 = tmp4->next;
    }
    tmp4->next = tmp2->next;
    ListNode* t = tmp1;
    vector<ListNode *> vec;
    while(t != tmp2) {
        vec.push_back(t);
        t = t->next;
    }
    for (int i = 0; i < vec.size(); ++i) {
        delete vec[i];
    }
    return list1;
}