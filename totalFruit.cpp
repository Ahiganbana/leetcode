#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = tree.size();
        if(size ==0){
            return 0;
        }
        int i = 0, j = 0, res = 1, counter = 1;
        unordered_map<int, int> um;
        um[tree[0]]++;
        for (; i < size;){
            if(j + 1 < size && ((counter > 0 && tree[j + 1] != tree[i]) || (tree[j + 1] == tree[i] || um[tree[j + 1]] > 0))) {
                if (counter > 0 && tree[j + 1] != tree[i]){
                    counter--;
                }
                j++;
                um[tree[j]]++;
            }else{
                if (counter == 0 || (counter > 0 && j == size - 1)){
                    res = max(res, j - i + 1);
                }
                um[tree[i]]--;
                if(um[tree[i]] == 0) {
                    counter++;
                }
                i++;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    int n = 0;
    cin >> n;
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    int result = solution.totalFruit(tree);
    cout << result << endl;
    system("pause");
    return 0;
}