#include <stdio.h>
#include <limits.h>
int divide_result(int dividend_num, int divisor_num){
    int sign = 1;
    long int output = 0;
    if (dividend_num < 0) {
        sign *= -1;

    } else {
        dividend_num *= -1;
    }
    if (divisor_num < 0) {
        sign *= -1;

    } else {
        divisor_num *= -1;
    }
    while (dividend_num <= divisor_num) {
        long int temp = 0;
        long int div = divisor_num;
        while (dividend_num <= div) {
            temp += (temp+1);
            dividend_num -= div;
            div += div;
        }
        if (output >= INT_MAX) {
            if (sign == -1) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        output += temp;
    }
    return output * sign;
}
int main(void)
{
    int dividend_num = 17;
    int divisor_num = 2;
    printf("\nDividend %d, Divisior %d  ",dividend_num, divisor_num);
    printf("\nResult: %d  ",divide_result(dividend_num, divisor_num));
    dividend_num = -17;
    divisor_num = 5;
    printf("\n\nDividend %d, Divisior %d  ",dividend_num, divisor_num);
    printf("\nResult: %d  ",divide_result(dividend_num, divisor_num));
    dividend_num = 35;
    divisor_num = 7;
    printf("\n\nDividend %d, Divisior %d  ",dividend_num, divisor_num);
    printf("\nResult: %d  ",divide_result(dividend_num, divisor_num));
    return 0;
}