#include <stdio.h>

int main() {
    printf("Hello World\n");
    int result;
    int v1 = 121;
    int v2 = 0;
    result = v1 / v2; /* Ошибка!*/
    printf("Result of Divide by Zero is %d\n", result);
    return 0;
}