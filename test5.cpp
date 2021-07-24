#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    //记录字符串中出现的字符串数目
    unordered_set<char> st;
    for(int i = 0; i < s.size(); ++i) {
        st.insert(s[i]);
    }
    //使用滑动窗口 记录滑动窗口中字符串出现的数目
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int pos = 65536, len = 65536;
    while(j < s.size()) {
        mp[s[j]]++;
        if(mp.size() < st.size()) {
            ++j;
        }
        else if(mp.size() == st.size()) {
            pos = i;
            len = min(len, j - i + 1);
            mp[s[i]]--;
            if(mp[s[i]] == 0) {
                mp.erase(s[i]);
                ++j;
            }
            ++i;
        }
    }
    cout << pos << "," << len;
    system("pause");
    return 0;
}