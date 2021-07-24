#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int size = A.size();
        int res = 0, sum = 0;
        vector<int> freq(size, 0);
        freq[0] = 1;
        for(auto v : A){
            int t = sum + v - S;
            if(t >= 0) {
                //总和有多余的,减去t, 除去的方法有freq[t]种
                res += freq[t];
            }
            sum += v;
            freq[sum]++;
        }
        return res;
    }
};

int main(){
    Solution solution;
    int n = 0, S = 0;
    cin >> n >> S;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int result = solution.numSubarraysWithSum(A, S);
    cout << result << endl;
    system("pause");
    return 0;
}