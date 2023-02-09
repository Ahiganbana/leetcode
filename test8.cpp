#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

int getdigit(string &s, int &ptr) {
    int result = 0;
    string str;
    while(isdigit(s[ptr])) {
        str.push_back(s[ptr++]);
    }
    for(int i = str.size() - 1; i >= 0; --i) {
        result += pow(10, str.size() - i - 1) * (str[i] - '0');
    }
    return result;
}

double getAvg(vector<int> &arr, int &L, int K) {
    double sum = 0.0;
    for(int i = L; i < L + K; ++i) {
        sum += arr[i];
    }
    return sum / K;
}

double getMaxP(vector<int> &arr, int L, int K) {
    double maxP = 0.0;
    double preAvg = 0.0;
    double f = 0.0;
    for(int i = L; i < arr.size() - K; ++i) {
        double currAvg = getAvg(arr, i, K);
        if(i > L) {
            double currP = (currAvg - preAvg) / f;
            if(currP < 0) {
                currP = -currP;
            }
            maxP = currP - maxP > 0.0 ? currP : maxP;
        }
        f = currAvg - preAvg;
        preAvg = currAvg;
    }
    return maxP;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> input;
    int windowSize = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != ',' && s[i] != ':') {
            int tmp = getdigit(s, i);
            input.push_back(tmp);
        }
        if(s[i] == ':') {
            windowSize = s[i + 1] - '0';
            break;
        }
    }
    double result = getMaxP(input, 0, windowSize);
    cout << result;
}