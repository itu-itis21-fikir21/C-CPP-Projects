#include <stdio.h>

int subarray_sum(int size, int array[]){
int toplam=0, max=0;
for(int i =0;i<size;i++){
   if((toplam+array[i])<0){
    toplam=0;
   }
   else{
    toplam+=array[i];
    if(max<toplam){
        max=toplam;
    }
   }
}
return max;
}

int alternative(int size, int array[]){
    int sum=0;
    int if_max=subarray_sum(size, array);
    for(int i=0;i<size;i++){
        sum+=array[i];
        int temp2 = array[i]*(-1);
        array[i] =temp2;
    }
    int temp=subarray_sum(size, array);
    if((sum+temp)>if_max){
        return (sum+temp);
    }
    else{
        return if_max;
    }

}


int main(){
    int arr[7]= {8, -7,-10, 11, -5, 6, -10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int maximum = alternative(size, arr);
    printf("%d", maximum);
    return 0;
    
}
