#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int size = tokens.size();
        int score = 0, res = 0, i = 0, j = size - 1;
        sort(tokens.begin(), tokens.end());
        while (i <= j) {
            if(P >= tokens[i]) {
                P -= tokens[i];
                score += 1;
                i++;
            }else{
                if(score >= 1) {
                    P += tokens[j];
                    score -= 1;
                    j--;
                }else{
                    break;
                }
            }
            res = max(res, score);
        }
        return res;
    }
};

int main() {
    int n = 0, p = 0;
    cin >> n >> p;
    vector<int> tokens(n, 0);
    Solution solution;
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    int result = solution.bagOfTokensScore(tokens, p);
    cout << result << endl;
    system("pause");
    return 0;
}