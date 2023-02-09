#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char buf[1024], s[128];

char *strstr_(char* pSrc, char* pSub) {
    int len1 = strlen(pSrc);
    cout << len1 << endl;
    int len2 = strlen(pSub);
    cout << len2 << endl;
    for(int i = 0; i < len1; i++) {
        int j = 0;
        if(pSrc[i] == pSub[j]) {
            while(pSrc[i++] == pSub[j++]) {
                if(j == len2 - 1) {
                    return &pSrc[i - j];
                }
            }
        }
    }
    return NULL;
}

int FindSubString(char* pSrc, char* pSub) {
    char *pos = strstr_(pSrc, pSub);
    if(pos == NULL) {
        return -1;
    }else {
        return pos - pSrc + 1;
    }
}

int main() {
    scanf("%s", buf);
    scanf("%s", s);
    int res = FindSubString(buf, s);
    printf("%d\n", res);
    system("pause");
    return 0;
}