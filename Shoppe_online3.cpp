#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;


class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param order string字符串 
     * @return int整型vector
     */
    vector<int> GetEndPoint(string order) {
        // write code here
        vector<int> p = {0, 0};
        if(order.size() == 0) {
            return p;
        }
        unordered_map<char, vector<int>> mp = {{'W', {0, 1}}, {'A', {-1, 0},}, {'S',{0, -1}}, {'D', {1, 0}},
                                                {'w', {0, 1}}, {'a', {-1, 0},}, {'s',{0, -1}}, {'d', {1, 0}}
                                            };
        int step = 1;
        for (int i = 0; i < order.size(); ++i) {
            step = 1;
            if(isdigit(order[i])) {
                step = getStep(order, i);
                // step = order[i] - '0';
                vector<int> w = mp[order[i]];
                p[0] = p[0] + step * w[0];
                p[1] = p[1] + step * w[1];
            }else{
                vector<int> w = mp[order[i]];
                p[0] = p[0] + step * w[0];
                p[1] = p[1] + step * w[1];
            }
        }
        return p;
    }

    int getStep(string s, int &ptr) {
        string result = "";
        int num = 0;
        while(isdigit(s[ptr])) {
            result.push_back(s[ptr++]);
        }

        for(int i = result.size() - 1; i >= 0; --i) {
            if(result[i] >= '0' && result[i] <= '9') {
                num = num + pow(10, result.size() - 1 - i) * ( result[i] - '0' );
            }
        }
        return num;
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    vector<int> result = solution.GetEndPoint(s);
    cout << result[0] << " " << result[1] << endl;
    system("pause");
    return 0;
}

