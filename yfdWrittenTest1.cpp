#include <iostream>
#include<vector>
using namespace std;

int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<int> nums(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    vector<int> copynums(nums);
    int mid = N / 2;
    int left = 0, right = mid;
    int j = 0;
    for(int i = 0; i < M; ++i) {
        left = 0, right = mid, j = 0;
        while(left < mid && right < N && j < N) {
            copynums[j] = nums[right];
            copynums[++j] = nums[left];
            ++j;
            ++left;
            ++right;
        }
        nums.assign(copynums.begin(), copynums.end());
    }
    for(int i = 0; i < N; ++i) {
        cout << nums[i] << " ";
    }
    system("pause");
    return 0;
}