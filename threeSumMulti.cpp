#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int size = arr.size();
        int i = 0, j = size - 1, res = 0;
        int mod = 1000000007;
        unordered_map<int, int> um;
        vector<int> uniqNums;
        //计算数组中每个数出现的次数
        for(auto value : arr) {
            um[value]++;
        }

        //找到所有不重复的数
        for(const auto& key : um){
            uniqNums.push_back(key.first);
        }
        //排序
        sort(uniqNums.begin(), uniqNums.end());
        for (; i < uniqNums.size(); i++) {
            //取第一个数
            int ni = um[uniqNums[i]];
            cout << "ni = " << ni << endl;
            //满足 第一个数*3 = target的情况
            if(uniqNums[i]*3 == target && um[uniqNums[i]] >= 3) {
                // C(ni, 3)
                res += ni * (ni - 1) * (ni - 2) / 6;
            }
            //取第二个数
            for (j = i + 1; j < uniqNums.size(); j++) {
                int nj = um[uniqNums[j]];
                cout << "nj = " << ni << endl;
                //满足 第一个数 * 2 + 第二个数 = target的情况
                if(uniqNums[i] * 2 + uniqNums[j] == target && um[uniqNums[i]] > 1){
                    res += ni * (ni - 1) / 2 * nj;
                }
                //满足 第二个数 * 2 + 第一个数 = target的情况
                if(uniqNums[j] * 2 + uniqNums[i] == target && um[uniqNums[j]] > 1) {
                    res += nj * (nj - 1) / 2 * ni;
                }
                //取第三个数
                int c = target - uniqNums[i] - uniqNums[j];
                if(c > uniqNums[j] && um[c] > 0) {
                    res += ni * nj * um[c];
                }
            }
        }
        return res % mod;
    }
};

int main() {
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> arr(n, 0);
    Solution solution;
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    int result = solution.threeSumMulti(arr, target);
    cout << result << endl;
    system("pause");
    return 0;
}