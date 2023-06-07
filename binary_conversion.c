#include <stdio.h>
#include <stdlib.h>

int main(){
    int dec=0; int k=0; int bin; int temp=1;
    printf("enter the binary number: ");
    scanf("%d", &bin);

    for(; bin>0; bin=bin/10){
        if(bin%10 == 1){
            for(int i=0;i<k;i++){
                temp*=2;
            }
            dec+=temp;
            temp=1;
        }
        k++;
    }
    printf("%d", dec);
    return 0;
}