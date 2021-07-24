#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct node {
    int first;
    int second;
    bool operator < (const node & c) const{
        cout << "compare function" << endl;
        if((first == c.first)) {
            return false;
        }
        return first < c.second || (!(c.second < first) && (second < c.first));
    }
};
//找到数组中绝对值差为k的数对的个数
class Solution {
public:
    node n;
    int findPairs(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if(size == 0) {
            return 0;
        }
        int count = 0;
        typedef set<node> n_set;
        n_set s;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if(abs(nums[j] - nums[i]) == k) {
                    n.first = nums[i];
                    n.second = nums[j];
                    s.insert(n);
                }
            }
        }
        count = s.size();
        for (n_set::const_iterator p = s.cbegin(); p != s.cend(); ++p) {
            cout << "(" << (*p).first << "," << (*p).second << ")" << " ";
        }
        cout << "\n";
        return count;
    }
};

class Solution1 {
public:
    node n;
    int findPairs(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if(size == 0) {
            return 0;
        }
        int count = 0;
        int left = 0, right = 1;
        int diff = 0;
        while(right < size) {
            diff = nums[right] - nums[left];
            if(diff == k){
                count++;
                while(right < size - 1 && nums[right + 1] == nums[right]) {
                    right++;
                }
                while(left < right && nums[left + 1] == nums[left]) {
                    left++;
                }
                left++;
                do{
                    right++;
                } while (left >= right);
            }else if(diff > k){
                left++;
                if(left >= right) {
                    right++;
                }
            }else{
                right++;
            }
        }
        return count;
    }
};

int main() {
    int n, k = 0;
    cin >> n >> k;
    vector<int> nums(n, 0);
    Solution solution;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = solution.findPairs(nums, k);
    cout << result << endl;
    system("pause");
    return 0;
}