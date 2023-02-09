#include <iostream>
#include <vector>
using namespace std;
bool flag = false;
void canEscape(vector<vector<int>> &arr, int i, int j, int sec, vector<vector<int>> &visited) {
    if(i < 0 || i > arr.size() - 1 || j < 0 || j > arr[0].size() - 1) {
        return;
    }
    if(visited[i][j] == 1) {
        return;
    }
    if(i == arr.size() - 1 && j == arr[0].size() - 1) {
        if(sec <= arr[i][j]) {
            flag = true;
        }
        return;
    }
    visited[i][j] = 1;
    canEscape(arr, i + 1, j, sec + 1, visited);
    canEscape(arr, i - 1, j, sec + 1, visited);
    canEscape(arr, i, j + 1, sec + 1, visited);
    canEscape(arr, i, j - 1, sec + 1, visited);
}

int main() {
    int total = 0;
    cin >> total;
    for(int i = 0; i < total; ++i) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> input(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int startRow = 0, startCol = 0;
        flag = false;
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                cin >> input[j][k];
                if(input[j][k] == 0) {
                    startRow = j;
                    startCol = k;
                }
            }
        }
        canEscape(input, startRow, startCol, 0, visited);
        if(flag) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}