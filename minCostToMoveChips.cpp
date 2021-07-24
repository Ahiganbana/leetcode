#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int num = position.size();
        vector<int> costs(num, 0);
        for(int i = 0; i < num; ++i) {
            int cost = 0;
            for(int j = 0; j < num; ++j) {
                if(position[i] == position[j]) {
                    continue;
                }
                if(abs(position[j] - position[i]) % 2 != 0) {
                    ++cost;
                }
            }
            costs[i] = cost;
        }
        return *min_element(costs.begin(), costs.end());
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> position(n, 0);
    Solution solution;
    for (int i = 0; i < n; ++i) {
        cin >> position[i];
    }
    int result = solution.minCostToMoveChips(position);
    cout << result << endl;
    system("pause");
    return 0;
}