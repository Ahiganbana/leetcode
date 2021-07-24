#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        int left = 0, right = size - 1, res = 0;
        while(left <= right) {
            if(left == right) {
                res++;
                return res;
            }
            if(people[left] + people[right] <= limit){
                left++;
                right--;
            }else{
                right--
            }
            res++;
        }
        return res;
    }
};

int main(){
    Solution solution;
    int n = 0, limit = 0;
    cin >> n >> limit;
    vector<int> people(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    int result = solution.numRescueBoats(people, limit);
    cout << result << endl;
    system("pause");
    return 0;
}
