#include <iostream>
#include <vector>
#include <string>
using namespace std;

//判断一个由字母组成的矩阵中是否含有给定的单词
class Solution {
public:
    //使用DFS
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if(rows == 0) {
            return false;
        }
        int columns = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if(flag) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& s, int k) {
        //出口条件
        if(board[i][j] != s[k]) {
            return false;
        }else if(k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        bool result = true;
        //遍历每个方向
        for(auto const& dir : direction){
            int nextRow = i + dir.first, nextColumn = j + dir.second;
            if(nextRow >= 0 && nextRow < board.size() && nextColumn >= 0 && nextColumn < board[0].size()) {
                if(!visited[nextRow][nextColumn]) {
                    bool flag = check(board, visited, nextRow, nextColumn, s, k + 1);
                }
            }
            if(flag) {
                result = true;
                break;
            }
        }
        visited[i][j] = false;
        return result;
    }
};