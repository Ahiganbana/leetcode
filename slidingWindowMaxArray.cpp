// 实现滑动窗口中求最大值的结构 使用双端队列
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class WindowMax {
    int L;
    int R;
    vector<int> arr;
    deque<int> qmax;

    WindowMax(vector<int> &a) {
        arr = a;
        L = -1;
        R = 0;
    }

    void addFromRight() {
        if(R == arr.size()) {
            return;
        }
        while(!qmax.empty() && qmax.back() <= arr[R]) {
            qmax.pop_back();
        }
        qmax.push_back(arr[R]);
        R++;
    }

    void removeFromLeft() {
        if(L >= R - 1) {
            return;
        }
        L++;
        while(qmax.front() == L) {
            qmax.pop_front();
        }
    }

    int getMax() {
        if(!qmax.empty()) {
            int index = qmax.front();
            qmax.pop_front();
            return arr[index];
        }
    }
}