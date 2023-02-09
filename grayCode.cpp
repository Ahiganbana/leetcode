#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<bool> visited;
    vector<int> res;
public:
    vector<int> grayCode(int n) {
        visited.resize(1 << n, false);
        // i 表示当前的数, k是当前格雷码的长度
        process(n, 0, 1);
        return res;
    }

    bool process(int n, int i, int k) {
        if(visited[i]) {
            return false;
        }

        res.push_back(i);

        if(k == (1 << n)) {
            return true;
        }
        visited[i] = true;
        for(int j = 0; j <
         n; ++j) {
            if(process(n, i ^ (1 << j), k + 1)) {
                return true;
            }
        }
        res.pop_back();
        visited[i] = false;
        return false;
    }
};

int main() {
    int n = 2;
    Solution solution;
    vector<int> res = solution.grayCode(n);
    for(auto x : res) {
        cout << x << " ";
    }

    system("pause");
    return 0;
}