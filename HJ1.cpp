#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s.erase(s.find_last_not_of(' ') + 1); 
    int count = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if(s[i] != ' ') {
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}