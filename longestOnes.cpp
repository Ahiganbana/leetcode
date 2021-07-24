#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int size = A.size();
        int i = 0, j = 0, res = 0;
        for (; i < size; ){
            if(j < size && ((A[j] == 0 && K > 0) || A[j] == 1)){
                if(A[j] == 0) {
                    K--;
                }
                j++;
            }else{
                if(K == 0 || ((j == size) && K > 0)) {
                    res = max(res, j - i);
                }
                if(A[i] == 0) {
                    K++;
                }
                i++;
            }
        }
        return res;
    }
};

int main() {
    int n = 0, K = 0;
    Solution solution;
    cin >> n >> K;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int result = solution.longestOnes(A, K);
    cout << result << endl;
    system("pause");
    return 0;
}
