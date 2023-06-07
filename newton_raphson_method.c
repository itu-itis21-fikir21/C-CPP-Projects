#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VALUE 0.001
#define ERROR 0.001

int main(){
    double a, b, c, y, y2, y3, m; 
    double x=1;
   printf("enter the coefficients: ");
   scanf("%lf %lf %lf", &a, &b, &c);

    while(fabs(a*x*x + b*x + c)>ERROR){
        printf("%lf", x);
        y2= a*(x-VALUE)*(x-VALUE)+b*(x-VALUE)+c;
        y3 =a*(x+VALUE)*(x+VALUE)+b*(x+VALUE)+c;
        m= (y3-y2)/(2*VALUE);
        if (m==0) m+=VALUE;
        y=a*x*x + b*x + c;
        x= x - (y/m);
    }
    printf("root is %lf", x);

    return 0;
}