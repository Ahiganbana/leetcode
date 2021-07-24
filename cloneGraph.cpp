#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node{
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//图的遍历
class Solution {
     unordered_map<Node *, Node *> visited;
public:
    //方法一： 深度优先搜索, 递归实现
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        //使用map存储已经遍历过的节点
        if(visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        //遍历该节点的邻居并更新克隆节点的邻居节点
        for(auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }

    //方法一： 深度优先搜索， 非递归实现
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }

    }

    //方法二： 广度优先搜索
    Node* clonenGraph(Node* node) {
        if(!node) {
            return node;
        }
        unordered_map<Node *, Node *> visited;
        queue<Node *> q;
        q.push(node);
        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        //使用队列
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            for(auto n : tmp->neighbors) {
                //未被访问过
                if(visited.find(n) == visited.end()) {
                    Node *cnode = new Node(n->val);
                    visited[n] = cnode;
                    q.push(n);
                }
                visited[tmp]->neighbors.emplace_back(visited[n]);
            }
        }
        return visited[node];
    }
};