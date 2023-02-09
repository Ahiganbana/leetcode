// 最小生成树算法实现

#include <iostream>
#include <vector>
#include "graphTemplate.h"
#include <unordered_map>
#include <priority_queue>
using namespace std;

// 模拟并查集的结构
class Mysets{
    unordered_map<Node *, vector<Node *>> setMap;

public:
    Mysets(vector<Node*> nodes) {
        for(Node *cur : nodes) {
            vector<Node *> set;
            set.push_back(cur);
            setMap.insert(make_pair(cur, set));
        }
    }

    // 判断两个集合是否相同
    bool isSameSet(Node *from, Node *to) {
        vector<Node *> fromSet = setMap[from];
        vector<Node *> toSet = setMap[to];
        return fromSet == toSet;
    }

    void union(Node *from, Node *to) {
        vector<Node *> fromSet = setMap[from];
        vector<Node *> toSet = setMap[to];
        for(Node *toNode : toSet) {
            fromSet.push_back(toNode);
            setMap.insert(make_pair(toNode, fromSet));
        }
    }
};

bool operator < (Edge *e1, Edge *e2) {
    return e1->weight < e2->weight;
}

// kruskal 算法实现
unordered_set<Edge> kruskaMST(Graph *graph) {
    vector<Node *> nodeSet;
    for(auto &x : graph->nodes) {
        nodeSet.push_back(x.second);
    }
    Mysets unionFind(nodeSet);
    priority_queue<Edge, vector<Edge>, less<Edge>> priorityQueue;
    for(Edge &edge : graph->edges) {
        priorityQueue.push(edge);
    }
    unordered_set<Edge *> result;
    while(!priorityQueue.empty()) {
        Edge *edge = priorityQueue.front();
        priprityQueue.pop();
        if(!unionFind.isSameSet(edge->from, edge->to)) {
            result.push_back(edge);
            unionFind.union(edge->from, edge->to);
        }
    }
    return result;
}