#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int round(double num){
int whole = num;
return whole;
}

int week(int a, int b, int c){
int weekday = (c + round(13*(b+1)/5) + (a%100) + round((a%100) / 4) + round(round(a/100)/4) + 5*round(a/100)) % 7;

return weekday ;
}

int main(){
    int a, b, c, end;
    printf("Enter the date:");
    scanf("%d %d %d", &a, &b, &c); 
    if(((b>12) || (b<1)) || ((c>31) || (c<1))){
    printf("your month or day is invalid..");
    return 1;
}  
    printf("enter the end year: ");
    scanf("%d", &end);
    int count = 0;
    int temp0 = a;
    int res = week(a, b, c);
    switch (week(a, b, c)){
    case 0:
     printf("It's a saturday");
     break;
    case 1:
    printf("It's a Sunday");
    break;
    case 2:
    printf("It's a monday");
    break;
    case 3:
    printf("It's a tuesday");
    break;
    case 4:
    printf("It's a wednesday");
    break;
    case 5:
    printf("It's a thursday");
    break;
    case 6:
    printf("It's a friday");
    break;
    default:
    printf("invalid number!");
    break;
}
    for(; a<end; a++){
        if(week(a, b, c) == res){
            count++;
        }
    }
    printf("\nSame day-and-month on same weekday between %d and %d : %d", end, temp0, count);

    return 0;
}

