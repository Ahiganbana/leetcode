#include <iostream>
using namespace std;

int maxAllOneBorder(vector<vector<int>> m) {
    if(m.size() == 0) {
        return 0;
    }
    int N = m.size();
    int M = m[0].size();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {

            // 枚举边长
            for (int order = 1; border <= min(N - i, M - j); ++ border) {
                // 找到所有以(i,j)为左上角点 border为边长的正方形
                // 验证正方形的四条边是不是否都是1
                // 使用预处理的方法 使用新的矩阵存放在每一个位置右方有多少连续的1 使用新的矩阵存放在每一个位置的下方有多少连续的1 
            }
        }
    }
}