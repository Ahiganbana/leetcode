#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//寻找欧拉路径
class Solution {
    unordered_map <string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> res;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //建立边集矩阵
        for(auto t : tickets) {
            vec[t[0]].push_back(t[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(const string& des) {
        while(vec.count(des) && vec[des].size() > 0) {
            string tmp = vec[des].top();
            vec[des].pop();
            dfs(move(tmp));
        }
        res.emplace_back(des);
    }
};