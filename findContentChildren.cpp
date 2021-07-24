#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int i = 0, j = 0;
        while(i < g.size()) {
            while(j < s.size()) {
                if(s[j] >= g[i]) {
                    ++cnt;
                    ++i;
                    ++j;
                }else{
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> g(n, 0);
    vector<int> s(m, 0);
    Solution solution;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> s[j];
    }
    int result = solution.findContentChildren(g, s);
    cout << result << endl;
    system("pause");
    return 0;
}