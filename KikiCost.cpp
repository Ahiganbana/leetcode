// 寻找最省钱的方式给女主播送进下一轮

#include <iostream>
#include <vector>
using namespace std;


// 第一代尝试版本 递归缺少出口
/**
 * 改进方案 : 
 * 1. 计算平凡解(使用已知条件为递归做限制) 记录花费的钱数,如果这个钱数已经大于某个分支花费的钱数可以不再继续走这个分支
 * 2. 限制人气不会超过2*end
 * */
int process1(int x, int y, int z, int end, int cur) {
    if(cur == end) {
        return 0;
    }

    int p1 = process1(x, y, z, end, cur + 2) + x;
    int p2 = process1(x, y, z, end, cur * 2) + y;
    int p3 = process1(x, y, z, end, cur - 2) + z;
    return min(p1, min(p2, p3));
}

// 改进版本的递归
/**
 * 1. preMoney 之前已经花了多少钱
 * 2. end 目标
 * 3. add times del 三种可以选择的方式
 * 4. start 当前来到的人气
 * 5. limitAim 人气达到什么程度可以不需要再尝试
 * 6. limitCoin 最大平凡解, 已经使用的币已经到达什么程度就不需要再尝试了
 * 返回最小币数
 * */

int process(int preMoney, int end, int add, int times, int del, int start, int limitAim, int limitCoin) {
    if(preMoney > limitCoin) {
        return INT_MAX;
    }

    if(start < 0) {
        return INT_MAX;
    }

    if(start >= 2 * end) {
        return INT_MAX;
    }

    if(start == end) {
        return preMoney;
    }

    int minVal = INT_MAX;
    // 使用人气+2的方式
    int p1 = process(preMoney + add, end, add, times, del, start + 2, limitAim, limitCoin);
    if(p1 != INT_MAX) {
        minVal = p1;
    }

    // 使用人气 * 2的方式
    int p2 = process(preMoney + times, end, add, times, del, start * 2, limitAim, limitCoin);
    if(p2 != INT_MAX) {
        minVal = min(minVal, p2);
    }

    // 使用人气 - 2的方式
    int p3 = process(preMoney + del, end, add, times, del, start - 2, limitAim, limitCoin);
    if(p3 != INT_MAX) {
        minVal = min(minVal, p3);
    }
    return minVal;
}

int minCcoins(int add, int times, int del, int start, int end) {
    if(start > end) {
        return -1;
    }
    return process(0, end, add, times, del, start, end * 2, ((end - start) / 2) * add);
}
