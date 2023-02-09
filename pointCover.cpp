// 找到长度为L的绳子能覆盖的最多的点数
#include <iostream>
#include <vector>
using namespace std;

int maxCoverPoint(vector<int> arr, int L) {
    // left 和 right 维护窗口内点的个数
    int left = 0;
    int right = 1;
    // curr 表示当前窗口内绳子的长度
    int curr = 0;
    int result = 0;
    while(left <= right && left < arr.size() && right < arr.size()) {
        curr += arr[right] - arr[left];
        result = max(result, right - left + 1);
        if(curr <= L) {
            right++;
        }else {
            left++;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {0, 13, 24, 35, 46, 57, 60, 72, 87};
    int L = 6;
    cout << maxCoverPoint(arr, L) << endl;
    system("pause");
    return 0;
}