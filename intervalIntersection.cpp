#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //求两个区间集合的交集
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int fsize = firstList.size(), ssize = secondList.size();
        vector<vector<int>> res;
        int fi = 0, sj = 0;
        while(fi < fsize && sj < ssize) {
            if(firstList[fi][0] > secondList[sj][1]) {
                //第一个数组中所代表的集合在第二个数组中所代表集合的右边
                sj++;
            }else if(firstList[fi][1] < secondList[sj][0]) {
                //第一个集合在第二个集合的左边
                fi++;
            }else{
                //两个集合有交集
                res.push_back({max(firstList[fi][0], secondList[sj][0]), min(firstList[fi][1], secondList[sj][1])});
                //移动位于左边集合的区间的指针
                if(firstList[fi][1] < secondList[sj][1]) {
                    fi++;
                }else{
                    sj++;
                }
            }
        }
        return res;
    }
};

int main() {
    int fsize = 0, ssize = 0;
    cin >> fsize >> ssize;
    Solution solution;
    vector<vector<int>> firstList(fsize, vector<int>(2, 0));
    vector<vector<int>> secondList(ssize, vector<int>(2, 0));
    for (int i = 0; i < fsize; i++) {
        cin >> firstList[i][0] >> firstList[i][1];
    }
    for (int j = 0; j < ssize; j++) {
        cin >> secondList[j][0] >> secondList[j][1];
    }
    vector<vector<int>> res = solution.intervalIntersection(firstList, secondList);
    for (int k = 0; k < res.size(); k++) {
        cout << "[" << res[k][0] << "," << res[k][1] << "]" << endl;
    }
    system("pause");
    return 0;
}

/*
4 4
0 2 5 10 13 23 24 25
1 5 8 12 15 24 25 26
*/