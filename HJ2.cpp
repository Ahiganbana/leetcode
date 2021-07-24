#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    string s;
    char c;
    getline(cin, s);
    cin >> c;
    if(c >= 'A' && c <= 'Z') {
        c = tolower(c);
    }
    unordered_map<char, int> mp;
    for(int i = 0; i < s.length(); ++i) {
        if(isalpha(s[i] && (s[i] >= 'A' && s[i] <= 'Z'))) {
            s[i] = tolower(s[i]);
        }
        mp[s[i]]++;
    }
    cout << mp[c] <<endl;
    system("pause");
    return 0;
}