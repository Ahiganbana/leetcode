// 贪心算法求所作项目的最大收益

#include<iostream>
#include <vector>
#include <queue>

class Node {
    int profit;
    int cost;
    Node (int p, int c) {
        profit = p;
        cost = c;
    }

    bool operator < (const Node& n) const {
        return this.cost < n.cost;
    }
}

struct nodeCompare {
    bool operator() (const Node &n1, const Node &n2) {
        return n1.profit > n2.profit;
    }
};

int findMaximizedCapital(int k, int &w, vector<int> &profits, vector<int> &capital) {
    priority_queue<Node*, vector<Node*>, nodeCompare> costQueue; // 小根堆
    priority_queue<Node*> profixQueue; // 大根堆

    // 所哟项目扔到锁池中,花费组织小根堆
    for (int i = 0; i < k; ++i) {
        costQueue.push(new Node(profits[i], capital[i]));
    }

    for (int i = 0; i < k; ++i) {
        while(!costQueue.empty() && costQueue.front()->cost <= w) {
            profixQueue.add(costQueue.front());
            costQueue.pop();
        }
        if(profixQueue.empty()) {
            return w;
        }
        w += profixQueue.front().profix;
        profixQueue.pop();
    }
    return w;
}

