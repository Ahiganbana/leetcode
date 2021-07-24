#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int size = arr.size();
        int i = 0, j = 0, res = 0;
        bool status = true;
        for (; i < size;) {
            if(j + 1 < size && ((status == true && arr[j + 1] > arr[i] && arr[j + 1] > arr[j]) || (j != i && arr[j + 1] < arr[j]))){
                if(arr[j + 1] < arr[j]){
                    status = false;
                }
                j++;
            }else{
                if(j != i && status == false){
                    res = max(res, j - i + 1);
                }
                i++;
                if(j < i) {
                    j = i;
                }
                if(j == i){
                    status = true;
                }
            }
        }
        return res;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    Solution solution;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = solution.longestMountain(arr);
    cout << result << endl;
    system("pause");
    return 0;
}