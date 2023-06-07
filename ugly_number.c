#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* primes(int num, int* size) {
    int i = 2, k = 0;
    int capacity = 10;
    int* arr = (int*)malloc(capacity * sizeof(int));

    while (i <= num) {
        if (num % i == 0) {
            while (num % i == 0) {
                num = num / i;
            }
            if (k >= capacity) {
                capacity *= 2;
                arr = (int*)realloc(arr, capacity * sizeof(int));
            }
            arr[k] = i;
            k++;
        }
        i++;
    }

    *size = k;
    return arr;
}

int main() {
    int n_th;
    int j = 2;
    int num = 0;
    
    printf("Enter the value of n_th: ");
    scanf("%d", &n_th);
    
    while (num != n_th-1 && j < 1000) {
        int size;
        int* array = primes(j, &size);

        bool state = true;
        for (int i = 0; i < size; i++) {
            if (array[i] != 2 && array[i] != 3 && array[i] != 5) {
                state = false;
                break;
            }
        }
        
        free(array);

        if (state) {
            num++;
        }
        
        state = true;
        j++;
    }
    
    printf("%d. ugly number is %d\n", n_th, j-1 );
    
    return 0;
}
