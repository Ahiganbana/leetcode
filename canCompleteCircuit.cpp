// 加油站
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i = 0;
        int n = gas.size();
        while(i < n) {
            int sumOfGas = 0;
            int sumOfCost = 0;
            int cnt = 0;
            while(cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if(sumOfCost > sumOfGas) {
                    break;
                }
                else {
                    cnt++;
                }
            }
            if(cnt == n) {
                return i;
            }else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
    int i, cnt = 0, j = 0;
    for (i = 0; i < gasSize; i++) {
        if (gas[i] - cost[i] >= 0) {
            cnt = gas[i] - cost[i];
            j = i + 1;
            if (j > gasSize - 1)
                j = j % gasSize;
            for (; cnt > 0 && j != i;) {
                cnt = cnt + gas[j] - cost[j];
                j++;
                if (j > gasSize - 1)
                    j = j % gasSize;
            }
            if (j == i && cnt >= 0)
                return i;
        }
    }
    return -1;
}