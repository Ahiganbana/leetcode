#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return process(price, special, needs);
    }

    int process(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0;
        // 全部不使用大礼包的价格
        for(int i = 0; i < needs.size(); ++i) {
            res += needs[i] * price[i];
        }

        for(auto &item : special) {
            vector<int> cloneNeeds(needs);
            int j = 0;
            for(j = 0; j < needs.size(); ++j) {
                int diff = needs[j] - item[j];

                if(diff < 0) {
                    // 不能够使用大礼包
                    break;
                }
                // 所需要的数量变化
                cloneNeeds[j] = diff;
            }

            if(j == needs.size()) {
                res = min(res, item[j] + process(price, special, cloneNeeds));
            }
        }
        return res;
    }
};