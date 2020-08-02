#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class RewardOrNot {
    private :
        int luckyNumber;
        int reward;

        //存放一年内中奖的情况
        vector<int> resultInOneYear;

    public :
    RewardOrNot(int luckyNumber,int reward){
            this->luckyNumber = luckyNumber;
            this->reward = reward;
            resultInOneYear.resize(1000);
    }

    public :
    RewardOrNot() {
    }

    public :
     void setReward(int reward) {
            this->reward += reward;
    }

    public :
    int getLuckyNumber() {
            return luckyNumber;
    }

    //产生100-999范围内的数作为开奖结果
    public:
     int lotteryResult() {
            return (rand() % (999 - 100 + 1)) + 100;
    }

    public :
    void whetherTowin() {
            int temp = lotteryResult();
            if(temp == luckyNumber){
                setReward(500);
                resultInOneYear.push_back(1);
            }
            else{
                setReward(0);
                resultInOneYear.push_back(0);
            }
    }
    public :
    int getReward() {
        return reward;
    }

    public:
    vector<int> getResultInOneYear() {
        return resultInOneYear;
    }
};

int main() {
    cout << "input a luckyNumber : " << endl;
    int luckyNumber;
    cin >> luckyNumber;
    RewardOrNot ron = RewardOrNot(luckyNumber, -365);
    for (int i = 0; i < 365; i++) {
        ron.whetherTowin();
    }
    vector<int> result = ron.getResultInOneYear();
    // for (int i = 0; i < result.size();i++) {
    //     cout << result[i] << " ";
    //     if(i%10 == 0) {
    //         cout << endl;
    //     }
    // }
    cout << ron.getReward();
    system("pause");
}
