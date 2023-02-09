// 贪心算法找到最小的分割金条的方式
#include <priority_queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lessMoney(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < arr.size(); ++i) {
        q.push(arr[i]);
    }
    int sum = 0;
    int cur = 0;
    while(q.size() > 1) {
        cur = q.front();
        q.pop();
        cur += q.front();
        q.pop();
        sum += cur;
        q.push(cur);
    }
    return sum;
}
