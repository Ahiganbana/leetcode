#include <iostream>
#include <vector>
using namespace std;

struct Employee {
    int happy; // 员工能够带来的快乐值
    vector<Employee *> nexts; //员工的直接下级
}

struct Info{
    int laiMaxHappy;
    int buMaxHappy;
    Info(int l, int b) : laiMaxhappy(l), buMaxhappy(b){}
};

// 返回能够获得的员工最大快乐值
Info *process(Employee *e) {
    if(e->nexts.size() == 0) { // 说明e是最基层的员工
        return new Info(e->happy, 0);
    }
    int lai = e->happy; // 来的情况下获得的快乐值
    int bu = 0; // 不来的情况下获得的快乐值
    for(auto &x : e->nexts) {
        Info *nextInfo = process(x);
        lai += nextInfo->buMaxHappy;
        bu += max(nextInfo->laiMaxHappy, nextInfo->buMaxHappy);
    }
    return new Info(lai, bu);
}


int getMapHappy(Employee *e) {
    Info *info = process(e);
    return max(info->laiMaxHappy, info->buMaxHappy);
}
