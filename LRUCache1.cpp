#include <iostream>
#include <unordered_map>
using namespace std;

struct LinkListNode{
    int value;
    int key;
    LinkListNode* prev;
    LinkListNode* next;
    LinkListNode(int k, int val):key(k), value(val), prev(nullptr), next(nullptr){}
};

class LRUCache {
    int maxSize = 0;
    int currSize = 0;
    unordered_map<int, LinkListNode*> mp;
    LinkListNode* head = new LinkListNode(-1, -1);
    LinkListNode* tail = new LinkListNode(-2, -2);

public:
    LRUCache(int capacity) {
        //完成初始化
        maxSize = capacity;
        head->next = tail;
        tail->prev = head;
        mp[-1] = head;
        mp[-2] = tail;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            LinkListNode* tmp = mp[key];
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
            return mp[key]->value;
        }else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        //需要完成更新
        if(mp.find(key) != mp.end()) {
            LinkListNode* tmp = mp[key];
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
            mp[key]->value = value;
        }else {
            //需要完成插入
            LinkListNode* newNode = new LinkListNode(key, value);
            if(currSize + 1 <= maxSize) {
                //可以直接插入的情况,插入链表头部
                currSize += 1;
            }else { 
                //需要移除一个再进行插入
                LinkListNode* removeNode = tail->prev;
                removeNode->prev->next = tail;
                tail->prev = removeNode->prev;
                mp.erase(removeNode->key);
            }
            head->next->prev = newNode;
            newNode->next = head->next;
            newNode->prev = head;
            head->next = newNode;
            mp[key] = newNode;
        }
    }
};

int main() {
    LRUCache *obj = new LRUCache(2);
    int param = obj->get(2);
    cout << param << endl;
    obj->put(2, 6);
    param = obj->get(1);
    cout << param << endl;
    obj->put(1, 5);
    obj->put(1, 2);
    param = obj->get(1);
    cout << param << endl;
    param = obj->get(2);
    cout << param << endl;
    param = obj->get(4);
    cout << param << endl;
    delete obj;
    system("pause");
    return 0;
}
