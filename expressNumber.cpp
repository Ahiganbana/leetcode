// 寻找字符串能够组成的可能的表达式的种数
#include <iostream>
#include <vector>
using namespace std;

// 检查给定的字符串是否合法:
// 1. 长度必须是奇数
// 2. 在偶数位置上的字符是0/1 奇数位置上的字符是逻辑运算符
bool isValid(string exp) {
    if((exp.size() & 1) == 0) {
        return false;
    }
    // 偶数位置的检查
    for (int i = 0; i < exp.size(); i += 2) {
        if(exp[i] != '0' && exp[i] != '1') {
            return false;
        }
    }

    // 奇数位置的检查
    for (int i = 1; i < exp.size(); i += 2) {
        if(exp[i] != '&' && exp[i] != '|' && exp[i] != '^') {
            return false;
        }
    }

    return true;
}

// exp[L...R] 返回期待为desired的方法数
// L 和 R不能压中逻辑符号
int process(string exp, bool desired, int L, int R) {
    if(L == R) {
        if(exp[L] == '1') {
            return desired ? 1 : 0;
        }else {
            return desired ? 0 : 1;
        }
    }

    int res = 0;
    // 开始做选择
    if(desired) {
        for (int i = L + 1; i < R; i += 2) {
            switch(exp[i]) {
                case '&':
                    res += process(exp, true, L, i - 1) * process(exp, true, i + 1, R);
                    break;
                case '|':
                    res += process(exp, true, L, i - 1) * process(exp, false, i + 1, R);
                    res += process(exp, false, L, i - 1) * process(exp, true, i + 1, R);
                    res += process(exp, true, L, i - 1) * process(exp, true, i + 1, R);
                    break;
                case '^':
                    res += process(exp, true, L, i - 1) * process(exp, false, i + 1, R);
                    res += process(exp, false, L, i - 1) * process(exp, true, i + 1, R);
            }
        }
    }else {
        for (int i = L + 1; i < R; i += 2) {
            switch(exp[i]) {
               case '&':
                    res += process(exp, false, L, i - 1) * process(exp, true, i + 1, R);
                    res += process(exp, false, L, i - 1) * process(exp, false, i + 1, R);
                    res += process(exp, true, L, i - 1) * process(exp, false, i + 1, R);
                    break;
                case '|':
                    res += process(exp, false, L, i - 1) * process(exp, false, i + 1, R);
                    break;
                case '^':
                    res += process(exp, true, L, i - 1) * process(exp, true, i + 1, R);
                    res += process(exp, false, L, i - 1) * process(exp, false, i + 1, R);
                    break;
            }
        }
    }
    return res;
}

int expressCnt(string exp, bool desired) {
    if(exp.size() == 0) {
        return 0;
    }

    if(isValid(exp)) {
        return 0;
    }

    return process(exp, desired, 0, exp.size() - 1);
}

// 动态规划解法
// 需要两张用于存储历史记录的变量 一个保存desired为false的情况,一个用于保存desired为true的情况
/**
 * 1. 初始化
 *  由于L < R 所以矩阵的下半区无效
 *  对角线的位置根据L压中的位置变化
 *  自下向上填表
 * 2. 动态转移方程
 * */

int dpProcess(string express, bool desired) {
    int N = express.size();
    vector<vector<int>> tMap(N, vector<int>(N, 0));
    vector<vector<int>> fMap(N, vector<int>(N, 0));

    // 初始化
    for (int i = 0; i < N; i += 2) {
        tMap[i][i] = express[i] == 1 ? 1 : 0;
        fMap[i][i] = express[i] == 1 ? 0 : 1;
    }

    // 动态转移
    for (int row = N - 3; row >= 0; row -= 2) {
        for (int col = row + 2; col < N; col += 2) {

            for (int i = row + 1; i < N; i += 2) {
                if(desired) {
                    switch(express[i]) {
                        case '&':
                            tMap[row][col] += tMap[row][i - 1] * tMap[i + 1][col];
                            break;
                        case '|':
                            tMap[row][col] += tMap[row][i - 1] * fMap[i + 1][col];
                            tMap[row][col] += fMap[row][i - 1] * tMap[i + 1][col];
                            tMap[row][col] += tMap[row][i - 1] * tMap[i + 1][col];
                            break;
                        case '^':
                            tMap[row][col] += tMap[row][i - 1] * fMap[i + 1][col];
                            tMap[row][col] += fMap[row][i - 1] * tMap[i + 1][col];
                            break;
                    }
                }else {
                    switch(express[i]) {
                        case '&':
                            fMap[row][col] += tMap[row][i - 1] * fMap[i + 1][col];
                            fMap[row][col] += fMap[row][i - 1] * fMap[i + 1][col];
                            fMap[row][col] += fMap[row][i - 1] * tMap[i + 1][col];
                            break;
                        case '|':
                            tMap[row][col] += fMap[row][i - 1] * fMap[i + 1][col];
                            break;
                        case '^':
                            tMap[row][col] += tMap[row][i - 1] * tMap[i + 1][col];
                            tMap[row][col] += fMap[row][i - 1] * fMap[i + 1][col];
                            break;
                    }
                }
            }
        }
    }
    return desired ? tMap[0][N - 1] : fMap[0][N - 1];
}