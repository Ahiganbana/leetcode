#include <iostream>
#include <vector>
using namespace std;

void printLevel(vector<vector<int>> m, int tR, int tC, int dR, int dC, bool f) {
    if(f) {
        while(tR != dR + 1) {
            // 从右上到左下打印
            cout << m[tR++][tC--] << " ";
        }
    }else {
        while(dR != tR - 1) {
            // 从左下到右上打印
            cout << m[dR--][dC++] << " ";
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    int ar = 0;
    int ac = 0;
    int br = 0;
    int bc = 0;
    int endR = matrix.size() - 1;
    int endC = matrix[0].size() - 1;
    bool fromUp = false;
    while(ar != endR + 1) {
        printLevel(matrix, ar, ac, br, bc, fromUp);
        ar = ac == endC ? ar + 1 : ar;
        ac = ac == endC ? ac : ac + 1;
        bc = br == endR ? bc + 1 : bc;
        br = br == endR ? br : br + 1;
        fromUp = !fromUp;
    }
    cout << endl;
    system("pause");
    return 0;
}