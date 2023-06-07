#include <stdio.h>
#include <stdlib.h>

void generate(int array[], int num){
    for(int i=0; i<num;i++){
        for(int j=num-i-1;j>0;j--){
            printf(" ");
        }
        for(int k=0;k<=i;k++){
            array[k]=k+1;
            array[2*i-k]=array[k];
        }
        for(int x=0;x<=2*i;x++){
            printf("%d", array[x]);
        }
        printf("\n");
    }
}

int main(){
    int size;
    int array[50];
    printf("enter the size: ");
    scanf("%d", &size);
    generate(array, size);
    return 0;
}