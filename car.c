#include <stdio.h>
#include <stdlib.h>


int main(){
int x, y, size, num_cars;
printf("Enter the sizes of grid: ");
scanf("%d", &size);
int grid[size][size];
for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
        grid[i][j]=0;
    }
}
int arr1[size], arr2[size];
printf("enter the number of cars: ");
scanf("%d", &num_cars);
int max =0, k=0;
while(k<num_cars){
    printf("Locations: ");
    scanf("%d %d", &x, &y);
    arr1[k] = x;
    arr2[k] = y;
    k++;
}
int distance=0;
for(int i = 0; i<size; i++){
    for (int j =0; j<size; j++){
    for(int x=k-1; x>=0; x--){
        distance = distance + abs(i-arr1[x]) + abs(j-arr2[x]);
    }
    if(max<distance){
        max = distance;
        grid[i][j] = max;
    }
    distance = 0;
    }
    }
for(int a=size-1; a>=0; a--){
    for(int b=size-1; b>=0; b--){
        if(grid[a][b] == max){
            printf("best slot: %d %d", a, b);
            return 0;
        }
    }
}   
}
