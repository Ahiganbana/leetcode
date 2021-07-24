#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> partation(vector<int> & arr, int L, int R) {
    int less = L - 1;
    int more = R;
    while(L < more) {
        if(arr[L] < arr[R]) {
            swap(arr[++less], arr[L++]);
        }else if(arr[L] > arr[R]) {
            swap(arr[--more], arr[L]);
        }else {
            L++;
        }
    }
    swap(arr[more], arr[R]);
    return {less + 1, more};
}

void quickSort(vector<int> &arr, int L, int R) {
    if(L < R) {
        srand(time(nullptr));
        int randomIndex = (int)(rand() % (R - L + 1)) + L;
        swap(arr[randomIndex], arr[R]);
        vector<int> p = partation(arr, L, R);
        quickSort(arr, L, p[0] - 1);
        quickSort(arr, p[1] + 1, R);
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}