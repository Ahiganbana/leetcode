#include <iostream>
#include <string>
using namespace std;

int solve(string s){
    int i = 0;
    int n = s.size();
    int res = 0;
    while(i < s.size() - 1){
        if(s[i] - '0' + s[i + 1] - '0' == 10){
            s.erase(i, 2);
            i = 0;
        }
        i++;
    }
    return s.size();
}

int main() {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    int result = solve(s);
    cout << result <<endl;
    system("pause");
    return 0;
}