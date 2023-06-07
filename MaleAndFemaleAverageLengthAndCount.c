#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(char people[][20], int num){
 int i=0; int k=0; double count1=0; double count2=0;
 int y=0; int x=0;
   for(int j=0;j<num;j++){
    if(people[j][0]=='M'){ 
        count1++;
         while(people[j][i]!='\0'){
          i++;
      }
      y+=i-2;
      i=0;
    }
    else{
        count2++;
        while(people[j][k]!='\0'){
            k++;
        }
        x+=k-2;
        k=0;
    }
 }
 printf("female count: %.2lf, avg. female length %.2lf\n", count2, count2 != 0 ? (x/count2) : 0);
 printf("male count: %.2lf, avg. male length %.2lf\n", count1, count1 != 0 ? (y/count1) : 0);
}

int generate_arr(char input[], char array[][20], int num){
   int i=0; int j=0; int k=0; 
    scanf("%[^\n]%*c", input);
    printf("%s\n", input);
   while(input[i] != '\0'){
    array[j][k] = input[i];
     i++; k++; 
    if(input[i] == ' '){
     j++; i++; k=0;
    }
   }
   num=j+1;
   if((array[0][0]=='\0') || (num>5)){
        printf("enter arguments 1 to 5!");
        return 1;
    }
    for(int i=0;i<num;i++){
        if((array[i][0] != 'M') && (array[i][0]!='F') && (array[i][0]!='\0')){
            printf("please enter the names with gender prefix!");
            return 1;
        }
    }
    for(int i=0; i<num;i++){
        if(array[i][2]=='\0'){
            printf("please enter at least one argument after gender prefix!");
            return 1;
        }
    }
    count(array, num);
    return 0;  
}

int main(){
    char names[5][20];
    int num=0;
    char input[50];
    printf("enter the names with gender prefix 'M' or 'F': " );
    generate_arr(input, names, num);
    return 0;
}