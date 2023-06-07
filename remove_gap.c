#include <stdio.h>
#include <stdlib.h>

int remove_gap(char* str, int size){
    int i=0;
    while(str[i]==' '){
        i++;
    }
   printf("%d ", i);
     int j=0;
    for(;j<size-i;j++){
        str[j]=str[j+i];
    }
    printf("%d\n", j);
    for(int k=0;k<j+1;k++){
        printf("%c", str[k]);
    }

    return 0;
}


int main(){
    int size;
    printf("enter the size:");
    scanf("%d", &size);
    char string[size];
    printf("enter the string: ");
    scanf("%[^\n]%*c", string);
    remove_gap(string, 7);

    return 0;
}