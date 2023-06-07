#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


int main(){
    int size=10;
    bool found=false;
    int array[10];
    printf("enter the array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d", &array[i]);
    }
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            for(int k=0;k<i;k++){
                if(array[k]==array[i]){
                    found=true;
                }
             }
            if(found==true){
                break;
            }
            else{
             if(array[i]==array[j]){
                count++;
            }
        }
        }
        if(found==false){
       printf("%d occurs %d times\n", array[i], count);
       count=0;
        }
        found=false;
    }
    return 0;
}