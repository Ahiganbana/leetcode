#include<iostream>
#include<vector>
using namespace std;

void change(vector<int>& nums, int start) {
    int rightChild = 2 * start + 1;
    int tmp = nums[start];
    while(rightChild < nums.size()) {
        if(rightChild < nums.size() - 1 && nums[rightChild + 1] > nums[rightChild]) {
            ++rightChild;
        }
        if(nums[rightChild] > tmp) {
            nums[start] = nums[rightChild];
            start = rightChild;
            rightChild = 2 * start + 1;
        }else{
            break;
        }
    }
    nums[start] = tmp;
}

void genHeap(vector<int>& nums) {
    for (int i = nums.size() - 2 / 2; i >= 0; --i) {
        change(nums, i);
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> newnums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    genHeap(nums);
    for (int i = 0; i < nums.size(); ++i) {
        newnums[i] = nums[0];
        nums[0] = 0;
        change(nums, 0);
    }
    for (int i = 0; i < newnums.size(); ++i) {
        cout << newnums[i] << " ";
    }
    system("pause");
    return 0;
}