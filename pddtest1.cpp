#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct product{
    int id;
    int si;
    int ti;
    product(int i, int s, int t) : id(i), si(s), ti(t){}
};

bool compare(product p1, product p2) {
    if(p1.ti != p2.ti) {
        // 时间短的在前
        return p1.ti < p2.ti;
    }else{
        // 时间相同的情况下,收益大的在前
        return p1.si > p2.si;
    }
}

int process(vector<int> &vs, vector<int> &vt) {
    int n = vs.size();
    vector<product> p;
    for(int i = 0; i < n; ++i) {
        product pi(i, vs[i], vt[i]);
        p.push_back(pi);
    }
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i].si << " " << p[i].ti << endl;
    }

    int curDate = 1;
    int maxDate = p[n - 1].ti;
    int curVal = 0;
    int maxVal = INT_MIN;
    int j = 0;
    for (; curDate <= maxDate; ++curDate) {
        int date = curDate;
        for (int i = j; i < n; ++i) {
            if(p[i].ti >= date) {
                curVal += p[i].si;
                maxVal = max(curVal, maxVal);
            }
            ++date;
        }
        ++j;
    }
    return maxVal;
}

int main() {
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int N = 0;
        cin >> N;
        vector<int> vS(N, 0);
        vector<int> vT(N, 0);
        for(int j = 0; j < N; ++j) {
            cin >> vS[j] >> vT[j];
        }
        int res = process(vS, vT);
        cout << res << endl;
    }
    system("pause");
    return 0;
}