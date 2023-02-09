// 汉诺塔问题
/**
 * 问题可以抽象成将N个圆盘从from移动到to 借助中间的圆盘other
 * 需要满足的规则 : 小的圆盘不能在大圆盘的下面
 * 主要的步骤 : 1 ~ i-1 号盘从from->other
 *             i 号盘从from到to
 *             1 ~ i- 1 号盘从other->to
 * */
#include <iostream>
#include <string>
using namespace std;

void hanoi(int n) {
    if(n > 0) {
        func(n, "左", "中", "右");
    }
}

void func(int i, string start, string end, string other) {
    if(i == 1) {
        cout << "Move 1 from " << start << " to " << end;
    }
    else {
        func(i - 1, start, other, end);
        cout << "Move " << i << " from " << start << " to " << end;
        func(i - 1, other, end, start);
    }
}