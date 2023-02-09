// 返回bob活下来的概率

long process(int N, int M, int row, int col, int rest) {
    if(row < 0 || row == N || col < 0 || col == M) {
        return 0;
    }
    if(rest == 0) {
        return 1;
    }

    long live = process(N, M, row - 1, col, rest - 1);
    live += process(N, M, row, col - 1, rest - 1);
    live += process(N, M, row + 1, col, rest - 1);
    live += process(N, M, row, col + 1, rest - 1);
    return live;
}