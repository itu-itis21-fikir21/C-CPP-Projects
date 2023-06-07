#include <stdio.h>
#include <stdlib.h>

int main(){
    int size1=0, size2=0, size3=0;
    printf("enter the sizes of matrices: ");
    scanf("%d %d %d", &size1, &size2, &size3);
    int arr1[10][10], arr2[10][10];
    for(int i=0; i<size1; i++){
        for(int j=0;j<size2;j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i=0; i<size2; i++){
        for(int j=0;j<size3;j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    int sum;
    int result[10][10];
    for(int i=0; i<size1;i++){
        for(int j=0;j<size3;j++){
            sum=0;
            for(int k=0;k<size2;k++){
                sum=sum + arr1[i][k]*arr2[k][j];
               result[i][j]=sum;
            }
        }
    }
    for(int i=0;i<size1;i++){
        for(int j=0;j<size3;j++){
            if(j==0){
               printf("\n%d", result[i][j]);
            }
            else{
            printf(" %d", result[i][j]);
            }
        }
    }
    return 0;

}