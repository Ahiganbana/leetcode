// 找到1~n中没有出现的数
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void modify(int value, vector<int> &arr) {
    while(arr[value - 1] != value) {
        int tmp = arr[value - 1];
        arr[value - 1] = value;
        value = tmp;
    }
}

void printNumberNoInArray(vector<int> arr) {
    if(arr.size() == 0) {
        return;
    }

    for(int value : arr) {
        modify(value, arr);
    }

    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] != i + 1) {
            cout << i + 1 << endl;
        }
    }
}