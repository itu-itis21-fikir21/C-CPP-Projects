#include <stdio.h>
#include <stdbool.h>
int jump(int arr[], int size){
int pos=size-1;
for(int i=size-2;i>=0;i--){
   if(arr[i]+i>=pos){
    pos=i;
   }}
if(pos==0){printf("you win!");}
else{printf("you lose!");}
return 0;
}
int main(){
    int arr[8];
    printf("enter the array: ");
    for(int i=0;i<8;i++){
        scanf("%d", &arr[i]);
    }
    jump(arr, 8);
return 0;
}