// A 卷
//1. 求单词出现的频率
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<string> findKWords(vector<string> words, int k) {
    if(k > words.size()) {
        return words;
    }
    map<string, int> dic;

    for (int i = 0; i < words.size(); ++i) {
        dic[words[i]]++;
    }
    vector<pair<string, int>> v(dic.begin(), dic.end());
    sort(v.begin(), v.end(), cmp);
    vector<string> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(v[i].first);
    }
    return res;
}

// A 卷
// 计算掷骰子的概率
vector<float> allProbality(int n) {
    vector<float> base(6, 1.0 / 6.0);
    for (int i = 2; i <= n; ++i) {
        vector<float> tmp(5 * i + 1);
        for (int j = 0; j < base.size(); ++j) {
            for (int k = 0; k < 6; ++k) {
                tmp[j + k] += base[j] / 6.0;
            }
        }
        base = tmp;
    }
    return base;
}

//B 卷
// 找到x+y+z<target的三元组个数
int threeSum(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if(i > 0 && arr[i - 1] == arr[i]) {
            continue;
        }
        int t = target - arr[i];
        int k = arr.size() - 1;

        for (int j = i + 1; j < arr.size(); ++j) {
            if(j > i + 1 && arr[j - 1] - arr[j] == 0) {
                continue;
            }
            if(j == k) {
                break;
            }
            while(j < k && arr[j] + arr[k] > t) {
                --k;
            }
            if(arr[j] + arr[k] < t) {
                ans++;
            }
        }
    }
    return ans;
}

// B 卷
// 构造表达式
// 动态规划求解: dp[i][j]表示考虑前i个数,当前计算结果为j的方案数
// dp[i][j] = dp[i - 1][j + nums[i - 1]] + dp[i - 1][j - nums[i - 1]];

int process(vector<int> arr, int target, int cur, int i) {
    if(i == arr.size()) {
        return cur == target ? 1 : 0;
    }
    return process(arr, target, cur - arr[i], i + 1) + process(arr, target, cur + arr[i], i + 1);
}

int generateFormula(vector<int> arr, int target) {
    return process(arr, target, 0, 0);
}

int generateFormula(Vector<int> arr, int target) {
    int n = arr.size();
    int s = 0;
    for(int i : arr)
        s += abs(i);
    if(target > s) {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * s + 1, 0));
    dp[0][0 + s] = 1;
    for (int i = 1; i <= n; ++i) {
        int x = arr[i - 1];
        for (int j = -s; j <= s; ++j) {
            if((j - x) + s >= 0)
                dp[i][j + s] += dp[i - 1][(j - x) + s];
            if((j - x) + s <= 2* s)
                dp[i][j + s] += dp[i - 1][(j + x) + s];
        }
    }
    return dp[n][target + s];
}

int main() {
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target = 1;
    int result = generateFormula(nums, target);
    cout << result << endl;
    system("pause");
    return 0;
}