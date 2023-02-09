#include <iostream>
#include <vector>
using namespace std;

// 普通解法
int minBags(int apple) {
    if(apple & 1) {
        return -1;
    }
    int eightBagNum = apple / 8;
    int result = -1;
    int remainAppleNum = apple - eightBagNum * 8;
    while(eightBagNum >= 0 && remainAppleNum < 24) {
        int sixBagNum = rest % 6 == 0 ? rest / 6 : -1;
        if(sixBagNum != -1) {
            result = sixBagNum;
            break;
        }
        remainAppleNum = apple - 8 * (--eightBagNum);
    }
    return result == -1 ? -1 : result + eightBagNum;
}