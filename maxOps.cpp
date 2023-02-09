// 计算最多能够进行多少次magic操作
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

double avg(double sum, int size) {
    return sum / (double)size;
}

int maxOps(vector<int> arr1, vector<int> arr2) {
    double sum1 = 0;
    for (int i = 0; i < arr1.size(); ++i) {
        sum1 += arr1[i];
    }
    double sum2 = 0;
    for (int i = 0; i < arr2.size(); ++i) {
        sum2 += arr2[i];
    }
    if(avg(sum1, arr1.size()) == avg(sum2, arr2.size())) {
        return 0;
    }
    vector<int> arrMore;
    vector<int> arrLess;
    double sumMore = 0.0;
    double sumLess = 0.0;
    if(avg(sum1, arr1.size() > avg(sum2, arr2.size()))) {
        arrMore = arr1;
        sumMore = sum1;
        arrLess = arr2;
        sumLess = sum2;
    }else {
        arrMore = arr2;
        sumMore = sum2;
        arrLess = arr1;
        sumLess = sum1;
    }
    sort(arrMore.begin(), arrMore.end());
    unordered_set<int> setLess;
    for(int num : arrLess) {
        setLess.insert(num);
    }
    int moreSize = arrMore.size();
    int lessSize = arrLess.size();
    int ops = 0;
    for (int i = 0; i < arrMore.size() ++i) {
        double curr = (double)arrMore[i];
        if(curr < avg(sumMore, moreSize) && curr > avg(sumLess, lessSize) && !setLess.count(arrMore[i])) {
            sumMore -= curr;
            moreSize--;
            sumLess += curr;
            lessSize++;
            setLess.insert(arrMore[i]);
            ops++;
        }
    }
    return ops;
}