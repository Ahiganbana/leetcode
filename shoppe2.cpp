#include<iostream>
#include<string>
using namespace std;


string caseTransform01(string s) {
    // 转换为第一个字母是大写的场景
    if(s.size() == 0) return "";
    if(isupper(s[0])) return s;
    if(islower(s[0])) {
        s[0] = toupper(s[0]);
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '-' || s[i] == '_') {
            s[i + 1] = toupper(s[i  + 1]);
            s = s.erase(i, 1);
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    string result = caseTransform01(s);
    cout << result << endl;
    system("pause");
    return 0;
}