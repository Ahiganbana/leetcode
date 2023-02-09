// N 皇后问题
int num1(int n) {
    if(n < 1) {
        return 0;
    }
    int record[n]; // record[i]用于记录第i个皇后放在了第几列
    return process(0, record, n);
}

// i表示当前行数 recored[0-i-1]表示之前的皇后 n表示一共多少行
// 返回最后有多少种摆放的方案
int process(int i, int *recored, int n) {
    if(i == n) {
        return 1;
    }

    int res = 0;
    for (int j = 0; j < n; ++j) {
        //当前i行的皇后,放在j列会不会和之前的(0,,i-1)的皇后共行,共列或者共斜线
        //如果是 皇后无效 不是认为有效
        if(isValid(record, i, j)) {
            recored[i] = j;
            res += process(i + 1, recored, n);
        }
    }
    return res;
}

bool isValid(int *record, int i, int j) {
    for (int k = 0; k < i; ++k) {
        // 按照斜率判断是否共斜线
        if(j == record[k] || abs(record[k] - j) == abs(i - k)) {
            return false;
        }
    }
    return true;
}


// 可以使用位运算进行优化 --> 优化检查合法性 
// 使用三个数分别表示列上的限制,左斜线上的限制和右斜线的限制
// 当前位置的皇后对下一行皇后的影响为 : 上一行的列限制 | 上一行的左斜线限制<<1 | 上一行的右斜线限制>>1