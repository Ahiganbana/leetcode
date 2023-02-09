//O (logN) 求斐波那契数列
#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> muliMatrix(vector<vector<int>> m1, vector<vector<int>> m2) {
    vector<vector<int>> res(m1.size(), vector<int>(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m2.size(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> matrixPower(vector<vector<int>> m, int p) {
    vector<vector<int>> res(m.size(), vector<int>(m[0].size(), 0));
    for (int i = 0; i < res.size(); ++i) {
        res[i][i] = 1;
    }
    vector<vector<int>> tmp = m;
    for (; p != 0; p >>= 1) {
        if((p & 1) != 0) {
            res = muliMatrix(res, tmp);
        }
        tmp = muliMatrix(tmp, tmp);
    }
    return res;
}

int fi(int n) {
    if(n < 1) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    vector<vector<int>> base = {{1, 1},
                                {1, 0}};
    vector<vector<int>> res = matrixPower(base, n - 2);
    return res[0][0] + res[1][0];
}

int main() {
    int n = 9;
    cout << fi(n) << endl;
    system("pause");
    return 0;
}