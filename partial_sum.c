
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pair_of_sums(int* array, int sum, int index){
    int pair[10]={-1};
    bool y;
    int x=1;
    for(int i=0;i<index-1; i++){  
      for(int j=i+1;j<index;j++){
        if((array[i] + array[j]) == sum){
            pair[x]=array[i]*array[j];
            for(int k=x-1; k>=0;k--){
                if(pair[k]== pair[x])
                    y = true;
                }
            if(y == true)
              break;
            else{
               printf("pair is: %d %d \n", array[i], array[j]);
               x++;
            }           
        }
      }
      y=false;
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
    pair_of_sums(array, sum, index);
    
    return 0;

}
