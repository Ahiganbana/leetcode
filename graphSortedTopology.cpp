// 图的拓扑排序
#include "graphTemplate.h"
#include <vector>
#include <unordered_map>
#include <queue>
#include <pair>
using namespace std;

vector<Node *> sortedTopology(Graph *graph) {
    // key 某个node value: 剩余的入度
    unordered_map<Node *, int> inMap;
    //找到入度为0的点入队
    queue<Node *> zeroInQueue;
    for(pair<int, Node*> p : graph->nodes) {
        inMap.insert(make_pair(p.second, p.second->in));
        if(p.second->in == 0){
            zeroInQueue.push(p.second);
        }
    }

    vector<Node *> result;
    while(!zeroInQueue.empty()) {
        Node *cur = zeroInQueue.front();
        zeroInQueue.pop();
        result.push_back(cur);
        for(Node *next : cur->nexts) {
            inMap.insert(make_pair(next, inMap[next] - 1));
            if(inMap[next] == 0) {
                zeroInQueue.push(next);
            }
        }
    }
    return result;
}