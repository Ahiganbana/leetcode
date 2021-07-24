//合并两个有序数组
#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &arr1, vector<int> &arr2) {
    vector<int> result;
    int len1 = arr1.size();
    int len2 = arr2.size();
    int i = 0, j = 0;
    for (i = 0, j = 0; i < len1 && j < len2;) {
        if(arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            ++i;
        }else {
            result.push_back(arr2[j]);
            ++j;
        }
    }
    if(i == len1 && j < len2) {
        for (; j < len2; ++j) {
            result.push_back(arr2[j]);
        }
    }
    if(j == len2 && i < len1) {
        for (; i < len1; ++i) {
            result.push_back(arr1[i]);
        }
    }
    return result;
}

int main() {
    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;
    vector<int> arr1(n1, 0);
    vector<int> arr2(n2, 0);
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }
    vector<int> arr3 = merge(arr1, arr2);
    for (int i = 0; i < arr3.size(); ++i) {
        cout << arr3[i] << " ";
    }
    system("pause");
    return 0;
}