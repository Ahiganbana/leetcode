#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int size = count.size();
        int i = 0;
        int sumi = 0, numi = 0;
        vector<double> res(5, 0.0);
        while(i < size){
            //从左边数第一个不为0的统计为最小值
            if(count[i] != 0) {
                if(res[0] == 0.0) {
                    res[0] = i;
                }
                res[1] = max(res[1], double(i));
            }
            numi += count[i];
            sumi += count[i] * i;
            i++;
        }
        //平均值
        res[2] = double(sumi) / double(numi);
        //中位数
        res[3] = findMedian(count, numi);
        //众数
        res[4] = max_element(count.begin(), count.end()) - count.begin();
        return res;
    }

    double findMedian(vector<int>& count, int num) {
        int counter = 0;
        int odd = num % 2;
        int idxl = num / 2, idxr = num / 2;
        if(odd == 0) {
            right++;
        }
        int mid = 0;
        for (int i = 0; i < count.size(); i++) {
            if(count[i] == 0) {
                continue;
            }
            if(counter < idxl && counter + count[i] >= idxl) {
                mid += i;
            }
            if(counter < idxr && counter + count[i] >= idxr) {
                mid += i;
            }
            counter += count[i];
        }
        return double(mid) / 2.0;
    }
};

int main() {
    vector<int> count(256, 0);
    Solution solution;
    int n = 0, j = 0, times = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> j >> times;
        count[j] = times;
    }
    vector<double> res = solution.sampleStats(count);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    system("pause");
    return 0;
}