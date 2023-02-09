#include <iostream>
#include <vector>
using namespace std;

class Solution {

    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        process(n, k, 1);
        return res;
    }

    void process(int n, int k, int i) {
        if(i == k + 1) {
            res.push_back(path);
            return;
        }

        for(int j = i; j <= n; ++j) {
            path.push_back(j);
            process(n, k, i + 1);
            path.pop_back();
        }
    }
};

int main(){
    int n = 4;
    int k = 2;
    Solution solution;
    vector<vector<int>> res = solution.combine(n, k);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << "]," << endl;
    }
    system("pause");
    return 0;
}