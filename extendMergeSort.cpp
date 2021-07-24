#include <iostream>
#include <vector>
using namespace std;

// 小和问题
/**
 * 在一个数组中每一个数左边比当前数小的数累加起来,叫做这个数组的小和
 * 求一个数组的小和
 * */
int smallSum = 0;
int merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> result(right - left + 1, 0);
    int p1 = left;
    int p2 = mid + 1;
    int i = 0;
    int res = 0;
    while(p1 <= mid && p2 <= right) {
        res += arr[p1] < arr[p2] ? arr[p1] * (right - p2 + 1) : 0;
        result[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p2 <= right) {
        result[i++] = arr[p2++];
    }
    while (p1 <= mid) {
        result[i++] = arr[p1++];
    }
    for (i = 0; i < result.size(); ++i) {
        arr[left + i] = result[i];
    }
    return res;
}


 int process(vector<int> &arr, int left, int right) {
     if(left == right) {
         return 0;
     }
     int mid = left + ((right - left) >> 1);
     return process(arr, left, mid) + process(arr, mid + 1, right) + merge(arr, left, mid, right);
 }

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = process(arr, 0, arr.size() - 1);
    cout << res << endl;
    system("pause");
    return 0;
}