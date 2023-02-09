#include <vector>
#include <iostream>
#include <pair>
#include <stack>
#include <unordered_set>
using namespace std;
using PII = pair<int, int>;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        stack<PII> stk; // 使用栈结构模拟 实际递归调用的栈
        stk.emplace(0, 0);
        auto hash_function = [](const PII &o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while(!stk.empty()) {
            if(seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if(remain_x == targetCapacity || remain_y == targetCapacity || remain_x + remain_y == targetCapacity) {
                return true;
            }
            //几种选择
            // 灌满 x
            stk.emplace(jug1Capacity, remain_y);
            // 灌满y
            stk.emplace(remain_x, jug2Capacity);
            // 倒空x
            stk.emplace(0, remain_y);
            // 倒空y
            stk.emplace(remain_x, 0);
            // 把x的水倒进y
            stk.emplace(remain_x - min(remain_x, jug2Capacity - remain_y), remain_y + min(remain_x, jug2Capacity - remain_y));
            // 把y的水倒进x
            stk.emplace(remain_x + min(remain_y, jug1Capacity - remain_x), remain_y - min(remain_y, jug1Capacity - remain_x));
        }
        return false;
    }
};