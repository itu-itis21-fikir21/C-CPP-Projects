#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1)
        return s;

    int n = strlen(s);
    int cycleLen = 2 * numRows - 2;

    char* ret = (char*)malloc((n + 1) * sizeof(char));
    ret[n] = '\0';

    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < n; j += cycleLen) {
            ret[index++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret[index++] = s[j + cycleLen - i];
        }
    }

    return ret;
}

int main() {
    char string[20];
    int row = 0;
    printf("Enter the string: ");
    scanf("%[^\n]%*c", string);
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    char* converted = convert(string, row);
    printf("Converted string: %s\n", converted);

    free(converted);
    return 0;
}