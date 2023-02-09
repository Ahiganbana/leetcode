// 安排最多的活动场次
// 贪心算法入门
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Program {
    int start;
    int end;
    Program(int s, int e) {
        start = s;
        end = e;
    }

    // 结束时间早的在前面
    bool operator < (Program p1, Program p2) {
        return p1.end < p2.end;
    }

    int bestArrange(vector<Program> programs, int timePoint) {
        sort(programs.begin(), programs.end());
        int result = 0;
        for (int i = 0; i < programs.size(); ++i) {
            if(timePoint <= programs[i].start) {
                result++;
                timePoint = programs[i].end;
            }
        }
        return result;
    }
}