#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sorted(int* array, int index){
   int min;
    for(int i=0; i<index;i++){
        for(int j=i+1;j<index;j++){
            if(array[j]<array[i]){
             min=array[j];
             array[j]=array[i];
             array[i]=min;
            }
        }
    }
}

int pairs(int* array, int sum, int index){
    sorted(array, index);
    bool x = false;
    for(int i=0;i<index-1;i++){
        for(int k=i-1;k>=0;k--){
            if(array[k]== array[i])
              x = true;
        }
          for(int j =i+1;j<index;j++){
            if(x==true){
                break;
            }
            else if((array[i] + array[j])==sum){
                printf("pair is %d %d\n", array[i], array[j]);
                break;
            }
        }
        x=false;
    }
}

int main(){
    int* array;
    int index, sum;
    printf("enter the desirable sum: ");
    scanf("%d", &sum);
    printf("enter the size of array: ");
    scanf("%d", &index);
    array = (int*)malloc(index * sizeof(int));   
    for(int i=0;i<index;i++){
        scanf("%d", &array[i]);
    }
    pairs(array, sum, index);
    
    return 0;

}