// 图的遍历
#include "graphTemplate.h"
#include <queue>
#include <unordered_set>
#include <stack>
using namespace std;

// 宽度优先遍历
void bfs(Node *node) {
    if(!node) {
        return;
    }
    queue<Node *> q;
    unordered_set<Node *> set;
    q.push(node);
    set.insert(node);

    while(!q.empty()) {
        Node *cur = q.front();
        q.pop();
        cout << cur->value;
        for(Node *next : cur->nexts) {
            if(set.find(next) == set.end()) {
                set.insert(next);
                q.push(next);
            }
        }
    }
}

void dfs(Node *node) {
    if(!node) {
        return;
    }
    stack<Node *> s;
    unordered_set<Node *> set;
    s.push(node);
    set.insert(node);
    while(!s.empty()) {
        Node *cur = s.top();
        s.pop();
        for(Node *next : cur->nexts) {
            if(set.find(next) == set.end()) {
                s.push(next);
                set.insert(next);
                cout << next->value << " ";
                break;
            }
        }
    }
}