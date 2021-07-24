#include <iostream>
#include <queue>
using namespace std;

/**
 * 已知一个几乎有序的数组, (几乎有序:如果将数组中每一个元素排好序,每个元素移动的距离可以不超过K,K相对数组来说比较小)
 * 选择合适的排序算法进行排序.
 * 思路: 构建小根堆 大小为K,在数组上滑动小根堆每次弹出堆顶元素
 * */

void sortedArrDistanceLessK(vector<int> arr, int k) {
    //构建一个小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    int index = 0;
    // 先将前k个数构建出小根堆
    for (; index <=  min(arr.size(), k);  ++index) {
        q.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); ++i, ++index) {
        q.push(arr[index]);
        arr[i] = q.top();
        q.pop();
    }

    while(!q.empty()) {
        arr[i++] = q.top();
        q.pop();
    }
}