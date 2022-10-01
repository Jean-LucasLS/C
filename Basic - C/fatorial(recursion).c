#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fat(int res){
    if (res == 0)
        res = 1;
    else
        res = res * fat(res - 1);
    return res;
}

int main(){
    int res = 4;
    res = fat(res);
    printf("%d", res);
    return 0;
}