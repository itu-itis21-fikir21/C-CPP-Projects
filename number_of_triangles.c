#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10
int tri(int arr[], int size){
	int number = 0;
	int i =0;
    while(i<size - 1){
	   for( int j = size; j>i ; j--){ 
		   for(int x = j-1 ; x>i ; x--){
			   if((abs(arr[j] - arr[x]) < arr[i]) && ((arr[j] + arr[x]) > arr[i])){
                   number++;
			   }
		   }
	   }
	   i++;
   }
   return number;
}

int main(){
	int arr[CAPACITY];
	int size=0; 
	printf("enter your array: ");
	int input = 0;
	while(size<CAPACITY){
		scanf("%d", &input);
		if(input == -1)
			break;
		else{
			arr[size] = input;
			size++;
		}
	}
	
   printf("number of triangles is %d\n", tri(arr, size));

   return 0;
}   
   
  