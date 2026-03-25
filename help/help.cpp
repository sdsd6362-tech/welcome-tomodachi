#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10000 /* 10000000 */
#define PER_LINE 10
#define SAMPLE_LINES 2

void insertSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void shuffleBigArray(int *bigIntArray, int bigSize)
{
    int i2, temp;
    unsigned int u_int30 = 0;
    for (int i = 0; i < bigSize; i++)
    {
        u_int30 = ((long)rand() << 15) | rand();
        i2 = u_int30 % bigSize;
        if (i != i2)
        {
            temp = bigIntArray[i];
            bigIntArray[i] = bigIntArray[i2];
            bigIntArray[i2] = temp;
        }
    }
}
int *genBigRandArray(int bigSize, int offset = 0)
{
    int* bigIntArray;
    bigIntArray = (int*)calloc(bigSize, sizeof(int));
    for (int i = 0; i < bigSize; i++)
    {
    bigIntArray[i] = i + offset;
    }
    void srand();
    shuffleBigArray(bigIntArray, bigSize);
    return bigIntArray;
}


void printArraySample(int *array, int size,
int per_line, int sample_lines)
{
    int count = 0;
    for (int i=0; i<sample_lines; i++) {
        for (int j = 0; j < per_line; j++) {
            printf("%7d ", array[count++]);
            if (count >= size)
            { printf("\n"); return; }
        }
        printf("\n");
    } // end for
    if (count >= size)
    return;

    if (count < (size - per_line * sample_lines))
        count = size - per_line * sample_lines;
    printf("\n . . . . . \n");
    for (int i = 0; i < sample_lines; i++) {
        for (int j = 0; j< per_line; j++) {
            printf("%7d ", array[count++]);
            if (count >= size)
            { printf("\n"); return; }
        }
        printf("\n");
    } // end for
    printf("\n");
}


int main()
{
int *array;
array = genBigRandArray(ARRAY_SIZE, 0);
printf("Before sort : \n");
printArraySample(array, ARRAY_SIZE, PER_LINE, SAMPLE_LINES);
insertSort(array, ARRAY_SIZE); // only for size <= 10000
printf("After sort : \n");
printArraySample(array, ARRAY_SIZE, PER_LINE, SAMPLE_LINES);
}