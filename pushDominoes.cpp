#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res = "";
        int i = 0, j = 1;
        for (; j < dominoes.length(); j++)
        {
            if(dominoes[j] == '.'){
                continue;
            }
            if(i > 0){
                res += dominoes[i];
            }
            int middle = j - i - 1;
            if(dominoes[i] == dominoes[j]){
                for (int k = 0; k < middle; k++) {
                    res += dominoes[i];
                }
            }else if(dominoes[i] == 'L' && dominoes[j] == 'R') {
                for (int k = 0; k < middle; k++) {
                    res += '.';
                }
            }else{
                for (int k = 0; k < middle / 2; k++) {
                    res += 'R';
                }
                for (int k = 0; k < middle % 2; k++) {
                    res += '.';
                }
                for (int k = 0; k < middle / 2; k++) {
                    res += 'L';
                }
            }
            i = j;
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "";
    cin >> s;
    string result = solution.pushDominoes(s);
    cout << result << endl;
    system("pause");
    return 0;
}