#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        if(size == 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < size - 1; i++) {
            //计算在(timeSeries[i], timeSeries[i+1])时间段内的中毒时间
            count += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return count + duration;
    }
};

int main() {
    Solution solution;
    int n, duration = 0;
    cin >> n >> duration;
    vector<int> timeSeries(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> timeSeries[i];
    }
    int result = solution.findPoisonedDuration(timeSeries, duration);
    cout << result << endl;
    system("pause");
    return 0;
}