#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &arr) {
    if(arr.size() == 0) {
        return 0;
    }

    int n = arr.size();
    int res = arr[0];
    int pre = arr[0];
    for (int i = 1; i < n; ++i) {
        pre = max(arr[i], arr[i] + pre);
        res = max(res, pre);
    }
    return res;
}

int maxAcculateSum(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int maxSize = INT_MIN;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(n, 0);
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                tmp[k] += arr[j][k];
            }
            maxSize = max(maxSize, maxSubArray(tmp));
        }
    }
    return maxSize;
}

int main() {
    int N = 0;
    cin >> N;
    vector<vector<int>> input(N, vector<int> (N ,0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> input[i][j];
        }
    }
    int res = maxAcculateSum(input);
    cout << res << endl;
    system("pause");
    return 0;
}