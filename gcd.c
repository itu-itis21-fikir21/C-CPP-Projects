#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50

int primes(int num, int* arr) {
    int k = 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            bool isPrime = true;
            for (int j = i - 1; j >= 2; j--) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                arr[k] = i;
                k++;
            }
        }
    }
    return k;
}

int gcd(int num1, int num2) {
    int* arr1 = (int*)malloc(SIZE * sizeof(int));
    int* arr2 = (int*)malloc(SIZE * sizeof(int));

    int count1 = primes(num1, arr1);
    int count2 = primes(num2, arr2);

    int multi = 1;
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            bool isPresent = false;
            for (int x = j - 1; x >= 0; x--) {
                if (arr2[x] == arr2[j]) {
                    isPresent = true;
                    break;
                }
            }
            if (!isPresent && arr1[i] == arr2[j]) {
                multi = multi * arr1[i];
            }
        }
    }

    free(arr1);
    free(arr2);

    return multi;
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    int result = gcd(x, y);
    printf("Greatest common divisor is %d\n", result);
    return 0;
}