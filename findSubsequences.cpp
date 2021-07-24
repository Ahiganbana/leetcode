#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    vector<int> tmp;
    vector<vector<int>> res;
    unordered_set<int> s;
    int size;

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        size = nums.size();
        for (int i = 0; i < (1 << n); ++i) {
            findSubsequences(i, nums);
            int hashValue = getHash(263, int(1E9) + 7);
            if(check() && s.find(hashValue) == s.end()) {
                res.push_back(tmp);
                s.insert(hashValue);
            }
        }
        return res;
    }

    void findSubsequences(int mask, vector<int> nums) {
        tmp.clear();
        for (int i = 0; i < size; i++) {
            if(mask & 1) {
                tmp.push_back(nums[i]);
            }
            mask >>= 1;
        }
    }

    bool check() {
        for (int i = 1; i < tmp.size(); ++i) {
            if(tmp[i] < tmp[i - 1]) {
                return false;
            }
        }
        return tmp.size() >= 2;
    }

    int getHash(int base, int mod) {
        int hashValue = 0;
        for(const auto &x : tmp) {
            hashValue = 1LL * hashValue * base % mod + (x + 101);
            hashValue %= mod;
        }
        return hashValue;
    }
};

