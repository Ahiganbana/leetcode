#include <iostream>
#include <vector>
using namespace std;

void rotateEdge(vector<vector<int>> &m, int a, int b, int c, int d) {
    int tmp = 0;
    for (int i = 0; i < d - b; ++i) {
        tmp = m[a][b + i];
        m[a][b + i] = m[c - i][b];
        m[c - i][b] = m[c][d - i];
        m[c][d - i] = m[a + i][d];
        m[a + i][d] = tmp;
    }
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    int tR = 0;
    int tC = 0;
    int dR = matrix.size() - 1;
    int dC = matrix[0].size() - 1;
    while(tR < dR) {
        rotateEdge(matrix, tR++, tC++, dR--, dC--);
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}