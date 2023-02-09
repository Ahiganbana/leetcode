#include <iostream>
#include <vector>
using namespace std;

int maxSubMatrixSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if(n == 0)
        return 0;
    int m = matrix[0].size();
    if(m == 0)
        return 0;
    int maxVal = INT_MIN;
    int cur = 0;
    vector<int> s;
    for (int i = 0; i != n; ++i) {
        s.resize(m, 0);
        for (int j = i; j != n; ++j) {
            // 计算i~j 行的最大累加和
            cur = 0;
            for (int k = 0; k != m; ++k) {
                s[k] += matrix[j][k];
                cur += s[k];
                maxVal = max(cur, maxVal);
                cur = cur < 0 ? 0 : cur;
            }
        }
    }
    return maxVal;
}

int main() {
    vector<vector<int>> matrix = {{-90, 48, 78}, {64, -40, 64}, {-81, -7, 66}};
    int res = maxSubMatrixSum(matrix);
    cout << res << endl;
    system("pause");
    return 0;
}