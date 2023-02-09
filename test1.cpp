#include <iostream>
using namespace std;

// 三目运算符优先级低于<<
int main() {
    cout << (10 < 60) ? 0 : false;
    system("pause");
    return 0;
}