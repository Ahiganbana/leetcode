#include <iostream>
#include <vector>
using namespace std;

// 基数排序

int maxbits(vector<int> arr) {
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        max = max(max, arr[i]);
    }
    int res = 0;
    while(max != 0) {
        res++;
        max /= 10;
    }
    return res;
}

void radixSort(vector<int> &arr, int L, int R, int digit) {
    const int radix = 10;
    int i = 0, j = 0;
    // 有多少个辅助空间
    vector<int> bucket(R - L + 1, 0);
    for (int d = 1; d <= dight; ++d) {
        vector<int> count(radix, 0);
        for (i = L; i <= R; ++i) {
            // 取出arr[i] 的第j位放进桶里
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; ++i){
            count[i] = count[i] + count[i - 1];
        }
        for (i = R; i >= L; i--) {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = L, j = 0; i <= R; i++,j++) {
            arr[i] = bucket[j];
        }
    }
}

void radixSort(vector<int> arr) {
    if(arr == null || arr.size() < 2) {
        return;
    }
    radixSort(arr, 0, arr.size() - 1, maxbits(arr));
}

int main() {

    system("pause");
    return 0;
}