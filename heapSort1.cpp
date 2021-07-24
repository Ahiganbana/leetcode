 #include <iostream>
 #include <vector>
using namespace std;

//上浮
void heapInsert(vector<int> & arr, int index) {
    while(arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

//下沉
void heapify(vector<int> &arr, int index, int heapSize) {
    int leftChild = index * 2 + 1;
    while(leftChild < heapSize) {
        // 从父亲和两个孩子三者之间选择最大的
        int largest = leftChild + 1 < heapSize && arr[leftChild + 1] > arr[leftChild] ? leftChild + 1 : leftChild;
        largest = arr[largest] > arr[index] ? largest : index;

        if(largest == index) {
            break;
        }
        swap(arr[largest], arr[index]);
        index = largest;
        leftChild = index * 2 + 1;
    }
}

// 排序
void heapSort( vector<int> &arr) {
    if(arr.size() < 2) {
        return;
    }
    //建堆
    for (int i = 0; i < arr.size(); ++i) {
        heapInsert(arr, i);
    }
    // 调整
    int heapSize = arr.size();
    swap(arr[0], arr[--heapSize]);
    while(heapSize > 0) {
        heapify(arr, 0, heapSize);
        swap(arr[0], arr[--heapSize]);
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    heapSort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}
