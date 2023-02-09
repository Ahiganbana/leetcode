#include <iostream>
#include <vector>
using namespace std;

int minPaint(string s) {
    int N = s.length();
    for (int i = 0; i <= N - 1; ++i) {
        if(i == 0) {
            // 统计[0-n-1]一共有多少个绿色, 全部染成红色
        }else if(i == N -1) {
            // 统计arr[0..n-1]一共有多少个R,全部染成G
        }else{
            // 统计arr[0..L]有多少个R 染成G 
            // 统计arr[i+1,N]多少个G 染成R
        }
    }
}