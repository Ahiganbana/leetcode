#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size = numbers.size();
        if(size == 0) {
            return 0;
        }
        int min_num = numbers[0];
        for (int i = 1; i < size; i++) {
            if(numbers[i] < min_num) {
                min_num = numbers[i];
                break;
            }
        }
        return min_num;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> input(n,0);
    Solution solution;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int result = solution.minArray(input);
    cout << result << endl;
    system("pause");
    return 0;
}