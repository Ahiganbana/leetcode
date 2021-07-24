#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task{
    int difficulty;
    int profit;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int wsize = worker.size();
        int dsize = difficulty.size();
        int wi = 0, di = 0;
        //获得总利益的最大值
        int maxProfit = 0;
        while(wi < wsize){
            //找到每个工人能够完成的最难的工作
            //每个员工获得的最大利益
            int wprofit = 0;
            di = 0;
            while(di < dsize){
                if(worker[wi] >= difficulty[di]){
                    wprofit = max(wprofit, profit[di]);
                }
                di++;
            }
            maxProfit += wprofit;
            wi++;
        }
        return maxProfit;
    }
    int maxProfitAssignment1(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int wsize = worker.size();
        int dsize = difficulty.size();
        if(dsize == 0 || profit.size() == 0 || wsize == 0) {
            return 0;
        }
        int maxProfit = 0;
        vector<Task> tasks(dsize, 0);
        for(int i = 0; i < dsize; i++) {
            Task t = {difficulty[i], profit[i]};
            tasks.push_back(t);
        }
        sort(worker.begin(), worker.end());
        sort(tasks.begin(), tasks.end(), cmp);

        for (int i = 1; i < dsize; ++i) {
            tasks[i].profit = max(tasks[i].profit, tasks[i - 1].profit);
        }
        int index = 0;
        for(auto w : worker){
            while(index < dsize && w >= tasks[index].difficulty){
                index++;
            }
            if (index > 0) {
                maxProfit += tasks[index - 1].profit;
            }
        }
        return maxProfit;
    }

    bool cmp(const Task& task1, const Task& task2){
        return task1.difficulty < task2.profit;
    }
};

int main(){
    Solution solution;
    int dsize = 0, psize = 0, wsize = 0;
    cin >> dsize >> psize >> wsize;
    vector<int> difficulty(dsize, 0), profit(psize, 0), worker(wsize, 0);
    for (int i = 0; i < dsize; i++) {
        cin >> difficulty[i] >> profit[i];
    }
    for (int i = 0; i < wsize; i++) {
        cin >> worker[i];
    }
    int result = solution.maxProfitAssignment(difficulty, profit, worker);
    cout << result << endl;
    system("pause");
    return 0;
}

/*
5 5 4
2 10 4 20 6 30 8 40 10 50
4 5 6 7
*/
