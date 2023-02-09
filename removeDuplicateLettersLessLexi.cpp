#include <iostream>
#include <vector>
#include <string>
using namespace std;

string removeLetters(string str) {
    if(str.size() < 2) {
        return str;
    }

    vector<int> map(256, 0);

    for (int i = 0; i < str.size(); ++i) {
        map[str[i]]++;
    }
    int minACSIndex = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(--map[str[i]] == 0) {
            break;
        }else {
            minACSIndex = str[minACSIndex] > str[i] ? i : minACSIndex;
        }
    }
    string s = str.substr(0, minACSIndex + 1);
    s = s.replace(minACSIndex, 1, "");
    return to_string(minACSIndex) + removeLetters(s);
}
