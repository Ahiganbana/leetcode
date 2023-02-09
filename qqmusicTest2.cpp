#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int cnt = 0;
    int FillArray(vector<int>& a, int k) {
        // write code here
        // 填入不超过k的数使数组递增
        vector<int> spaces;
        for(int i = 0; i < a.size(); ++i) {
            // 记录所有需要填入数字的解空间
            if(a[i] == 0) {
                spaces.push_back(i);
            }
        }
        dfs(a, k, spaces, 0);
        return cnt % 1000000007;
    }
    
    //  尝试时候的限制条件 : 填入的数需要比左边大并且比右边小
    void dfs(vector<int> &a, int k, vector<int>& spaces, int index) {
        // 对所有的空间进行尝试
        if(index == spaces.size()) {
            cnt++;
            return;
        }
        // 需要进行尝试的位置
        int i = spaces[index];
        // 尝试在此位置填上digit
        for(int digit = 1; digit <= k; ++digit) {
            if(i > 0 && i < a.size() - 1 && a[i - 1] <= digit && a[i + 1] >= digit) {
                // 能够完成填入
                a[i] = digit;
                dfs(a, k, spaces, index + 1);
            }
            // 说明需要填入的位置在第一个
            if(i == 0) {
                if(a[i + 1] >=  digit) {
                    a[i] = digit;
                    dfs(a, k, spaces, index + 1);
                }
            }
            
            // 说明需要填入的位置在最后一个
            if(i == a.size() - 1) {
                if(a[i - 1] <= digit) {
                    a[i] = digit;
                    dfs(a, k, spaces, index);
                }
            }
        }
    }
};

int main() {

    vector<int> a = {1, 0, 0};
    int k = 3;
    Solution solution;
    int res = solution.FillArray(a, k);
    cout << res << endl;
    system("pause");
    return 0;
}