/* BigArray.h */
#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H
#define BIG_ARRAY_THRESHOLD 10000
void printBigArraySample(int* array, int size, int items_per_line, int sample_lines);
void shuffleBigArray(int* array, int size);
int* genBigRandArray(int size, int offset);
void insertSort(int* array, int size);
void selectionSort(int* array, int size);
void mergeSort(int* array, int size);
void _mergeSort(int array[], int tmp_array[], int left, int right);
void quickSort(int* array, int size);
void _quickSort(int* array, int size, int left, int right);
int _partition(int* array, int size, int left, int right, int pivotIndex);
#endif