#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //  存放哪些数字是可以进行尝试的
    vector<vector<int>> res;
    // 标记已经访问过的位置
    vector<int> visited;
    int cnt;
    
public:
    int countArrangement(int n) {
       visited.resize(n + 1);
       res.resize(n + 1);
       cnt = 0;
       for(int i = 1; i <= n; ++i) {
           for(int j = 1; j <= n; ++j) {
               if(i % j == 0 || j % i == 0) {
                   res[i].push_back(j);
               }
           }
       }
       process(n, 1);
       return cnt;
    }

    void process(int n, int i) {
        if(i == n + 1) {
            cnt++;
            return;
        }

        for(auto x : res[i]) {
            if(!visited[x]) {
                visited[x] = 1;
                process(n, i + 1);
                visited[x] = 0;
            }
        }
    }

};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    int res = solution.countArrangement(n);
    cout << res << endl;
    system("pause");
    return 0;
}