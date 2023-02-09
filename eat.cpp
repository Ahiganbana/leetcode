#include <iostream>
#include <vector>
using namespace std;

// 先手后手吃草问题

string eat(int n) {
    if(n < 5) {
        return (n == 2 || n == 0) ? "second" : "first";
    }

    int base = 1; // 先手开始选择吃草的数量
    while(base <= n) {
        if(eat(n - base) == "second") {
            return "first";
        }
        if(base > n / 4) {
            break;
        }
        base *= 4;
    }
    return "second";
}

int main() {
    for (int i = 0; i <= 50; ++i) {
        cout << i << " : " << eat(i) << endl;
    }
    system("pause");
    return 0;
}