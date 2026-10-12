/* ----------------------------------------------------*/
/* ИМЯ: Пронкина Тамара Павловна ID пользователя: Uluyuluy */
/* СРОК : 12/10/2026 */
/* ПРАКТИЧЕСКАЯ РАБОТА №5: ОРГАНИЗАЦИЯ ПАМЯТИ */
/* ИМЯ ФАЙЛА: dynamic_array_variant17.c */
/* ВАРИАНТ 17: Анализ массива через указатель на функцию */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void analyze_array(int *arr, int size, int *pos_count, int *neg_sum) {
    int i;
    
    *pos_count = 0;
    *neg_sum = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] > 0) {
            (*pos_count)++;
        } else if (arr[i] < 0) {
            *neg_sum += arr[i];
        }
    }
}

int main() {
    int N = 8;
    int *arr = NULL;
    int positive_count;
    int negative_sum;
    int i;
    
    void (*func_ptr)(int*, int, int*, int*);

    arr = (int *)malloc(N * sizeof(int));
    
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    arr[0] = 5;   arr[1] = -3;  arr[2] = 0;   arr[3] = 12;
    arr[4] = -7;  arr[5] = -1;  arr[6] = 8;   arr[7] = 0;

    printf("Исходный массив:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    func_ptr = analyze_array;

    func_ptr(arr, N, &positive_count, &negative_sum);

    printf("Результаты анализа (через указатель на функцию):\n");
    printf("1. Количество положительных элементов: %d\n", positive_count);
    printf("2. Сумма отрицательных элементов:      %d\n", negative_sum);

    free(arr);
    arr = NULL;

    return 0;
}