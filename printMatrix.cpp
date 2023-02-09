#include <iostream>
#include <vector>
using namespace std;

void printEdge(vector<vector<int>>& m, int a, int b, int c, int d) {
    if(a == c) {
        for (int i = b; i <= d; ++i) {
            cout << m[a][i] << " ";
        }
    }
    else if(b == d) {
        for (int i = a; i <= c; ++i) {
            cout << m[i][b] << " ";
        }
    }else {
        int curC = b;
        int curR = a;
        while(curC != d) {
            cout << m[a][curC] << " ";
            curC++;
        }
        while(curR != c) {
            cout << m[curR][d] << " ";
            curR++;
        }
        while(curC != b) {
            cout << m[c][curC] << " ";
            curC--;
        }
        while(curR != a) {
            cout << m[curR][b] << " ";
            curR--;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int tR = 0;
    int tC = 0;
    int dR = matrix.size() - 1;
    int dC = matrix[0].size() - 1;
    while(tR <= dR && tC <= dC) {
        printEdge(matrix, tR++, tC++, dR--, dC--);
    }
    system("pause");
    return 0;
}