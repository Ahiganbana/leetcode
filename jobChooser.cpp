#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Job{
public:
    int money;
    int hard;

    Job(int m, int h) {
        money = m;
        hard = h;
    }
};

bool compare(const Job &j1, const Job &j2) {
    return j1.hard != j2.hard ? (j1.hard < j2.hard) : (j1.money > j2.money);
}

vector<int> getMoneys(vector<Job> &jobs, vector<int> &ability) {
    sort(jobs.begin(), jobs.end(), compare);
    // 使用有序set去重
    map<int, int> m;
    m.insert(pair<int, int>(jobs[0].hard, jobs[0].money));
    Job pre = job[0];
    for (int i = 1; i < jobs.size(); ++i) {
        if(jobs[i].hard != pre.hard && jobs[i].money > pre.money) {
            pre = jobs[i];
            m[pre.hard] = pre.money;
        }
    }
    vector<int> ans(ability.size(), 0);
    for (int i = 0; i < ability.size(); ++i) {
        auto key = m.lower_bound(ability[i]);
        if(key != m.end()) {
            ans[i] = key;
        }
    }
    return ans;
}
