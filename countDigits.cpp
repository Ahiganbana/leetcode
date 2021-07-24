#include<iostream>
using namespace std;

int main() {
    int n = 0, x = 0;
    cin >> n >> x;
    int result = 0;
    int j = 0;
    for(int i = 1; i <= n; ++i) {
        j = i;
        while(j != 0) {
            int d = j % 10;
            int g = j / 10;
            if(d == x || g == x) {
                result++;
            }
            j /= 10;
        }
    }
    cout << result;
    system("pause");
    return 0;
}