#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int cnt = 0;
int tmp[10000000];

void merge_sort(int l, int r, vector<int> v){
    if(l >= r){
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(l, mid, v);
    merge_sort(mid + 1, r, v);
    int pl = l, pr = mid + 1, tmpp = 0;
    while(pl <= mid && pr <= r) {
        if(v[pl] <= v[pr]) tmp[tmpp++] = v[pl++];
        else {
            tmp[tmpp++] = v[pr++];
            cnt += mid - pl + 1;
        }
    }
    while(pl <= mid) tmp[tmpp++] = v[pl++];
    while(pr <= r) tmp[tmpp++] = v[pr++];
    for(int i = 0; i < tmpp; ++i) v[i + l] = tmp[i];
}

int main(){
    int n = 0, m = 0;
    cin >> n;
    int sum = pow(2, n);
    vector<int> input(sum, 0);
    for(int i = 0; i < sum; ++i) {
        cin >> input[i];
    }
    cin >> m;
    vector<int> q(m, 0);
    for(int i = 0; i < m; ++i) {
        cin >> q[i];
    }
    vector<int> :: iterator iter;
    vector<int> result;
    //翻转
    for(int i = 0; i < m; ++i) {
        iter = input.begin();
        for (int j = 0; j < input.size(); j += pow(2, q[i]))
        {
            reverse(iter, iter + pow(2, q[i]));
            iter = iter + q[i] + 1;
        }
        //求逆序对
        merge_sort(0, input.size() - 1, input);
        result.push_back(cnt);
        cnt = 0;
    }
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] <<endl;
    }
    system("pause");
    return 0;
}
/*
2
2 1 4 3
4
1 2 0 2
*/

