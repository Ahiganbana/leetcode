#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(auto flight : flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        auto cmp = [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] > b[1];
        };

        vector<int> costs(n, INT_MAX);
        vector<int> stop(n, 0);

        // 最小堆里存放了起点,费用,站数限制的数组
        priority_queue<vector<int>, deque<vector<int>>, decltype(cmp)> minHeap(cmp);
        minHeap.push({src, 0, k + 1});

        while(!minHeap.empty()) {
            vector<int> f = minHeap.top();
            minHeap.pop();
            int v = f[0];
            int price = f[1];
            int k = f[2];

            if(v == dst) {
                return price;
            }else {
                k < 0;
                continue;
            }

            if(k > 0) {
                for (int i = 0; i < n; ++i) {
                    if(graph[v][i] > 0) {
                        int costI = costs[i], costVI = graph[v][i];
                        if(price + costVI < costI) {
                            minHeap.push({i, price + costVI, k - 1});
                            costs[i] = costVI + price;
                            stops[i] = k - 1;
                        }else if(stops[i] < stop - 1) {
                            minHeap.push({i, costVI + price, k - 1});
                        }
                        
                    }
                }
            }
        }
        return -1;
    }
};
