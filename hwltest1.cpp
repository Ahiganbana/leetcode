#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* memcpy_(void* pvTo, const void* pvFrom, int size) {
    char *psrc;
    char *pdst;
    if(NULL == pvTo || NULL == pvFrom) {
        return NULL;
    }
    
    if((pvFrom < pvTo) && (char *)pvFrom + size > (char *)pvTo) {
        psrc = (char *)pvFrom + size - 1;
        pdst = (char *)pvTo + size - 1;
        while(size--) {
            *pdst-- = *psrc--;
        }
    }else {
        psrc = (char*)pvFrom;
        pdst = (char*)pvTo;
        while(size--) {
            *pdst++ = * psrc++;
        }
    }
    return pvTo;
}

int main() {
    char buf[100] = "abcdefghijk";
    memcpy_(buf + 2, buf, 5);
    printf("%s\n", buf + 2);
    system("pause");
    return 0;
}