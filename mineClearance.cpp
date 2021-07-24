#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}}; 
vector<vector<char>> result;
vector<vector<bool>> visited;
void dfs(int i, int j, vector<vector<char>> vec) {
    if(visited[i][j]) {
        return;
    }
    visited[i][j] = 1;
    for(int k = 0; k < 8; ++k) {
        int nextRow = i + dir[k][0];
        int nextColumn = j + dir[k][1];
        if(nextRow >= 0 && nextRow < vec.size() && nextColumn >= 0 && nextColumn < vec[i].size()) {
            int t = result[nextRow][nextColumn] - '0';
            t++;
            result[nextRow][nextColumn] = t + '0';
                //dfs(nextRow, nextColumn, vec);
        }
    }
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> input(n, vector<char>(m, ' '));
    result.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; ++i) {
        result[i].resize(m);
        visited[i].resize(m);
        for(int j = 0; j < m; ++j) {
            result[i][j] = '0';
            cin >> input[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(input[i][j] == '*'){
                result[i][j] = '*';
                dfs(i ,j, input);
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

/*
3 3
* ? ?
? ? ?
? * ?
*/