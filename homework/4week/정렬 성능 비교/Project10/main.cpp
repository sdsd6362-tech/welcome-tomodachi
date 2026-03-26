#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "BigArray.h" 

void performance_measurements_sorting_small_array(); 
void performance_measurements_sorting_big_array(); 
void drawLine(char ch, int length);

void main()
{
	performance_measurements_sorting_small_array(); 
	performance_measurements_sorting_big_array();
}

void drawLine(char ch, int length)
{
	for (int i = 0; i < length; i++) { printf("%c", ch); }printf("\n");
}

void performance_measurements_sorting_small_array()
{
	int* array;
	int array_size;
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time_us;
	double elps_time_quickSort_us, elps_time_selectSort_us, elps_time_insertSort_us, elps_time_mergeSort_us = 0.0;
	QueryPerformanceFrequency(&freq);
	printf("1. Compare the performances of sorting algorithms for small array\n");
	drawLine('=', 82);
	printf(" Array size QuickSort[us] MergeSort[us] InsertionSort[us] SelectionSort[us]\n");
		drawLine('-', 82);
	for (int size = 10; size <= 150; size += 5)
	{
		array = genBigRandArray(size, 0);
		QueryPerformanceCounter(&t_before);
		quickSort(array, size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); // in usec
		double elps_time_quickSort_us = elapsed_time_us;
		shuffleBigArray(array, size);
		QueryPerformanceCounter(&t_before);
		mergeSort(array, size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); // 
		double elps_time_mergeSort_us = elapsed_time_us;
		shuffleBigArray(array, size);
		QueryPerformanceCounter(&t_before);
		selectionSort(array, size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); 
		double elps_time_selectSort_us = elapsed_time_us;
		shuffleBigArray(array, size);
		QueryPerformanceCounter(&t_before);
		insertSort(array, size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_us = ((double)t_diff * 1000000 / freq.QuadPart); 
		double elps_time_insertSort_us = elapsed_time_us;
		printf("%10d %15.2lf %15.2lf %15.2lf %15.2lf\n", size, elps_time_quickSort_us, elps_time_mergeSort_us, elps_time_insertSort_us, elps_time_selectSort_us);
		free(array);
	}
	drawLine('=', 82);
}

void performance_measurements_sorting_big_array()
{
	int* bigRandArray;
	int test_size;
	int test_sizes[] = { 100, 1000, 10000, 100000, 500000, 1000000,
	5000000, 10000000, 50000000, 100000000 };
	int n_test_sizes = sizeof(test_sizes) / sizeof(int);
	LARGE_INTEGER freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time_ms;
	double elps_time_quickSort_ms, elps_time_selectSort_ms, elps_time_insertSort_ms, elps_time_mergeSort_ms = 0.0;
	QueryPerformanceFrequency(&freq);
	printf("\n2. Compare the performances of sorting algorithms for big array\n");
	drawLine('=', 82);
	printf(" Array size QuickSort[ms] MergeSort[ms] InsertionSort[ms]SelectionSort[ms]\n");
	drawLine('-', 82);
	for (int i = 0; i < n_test_sizes; i++)
	{
		test_size = test_sizes[i];
		bigRandArray = genBigRandArray(test_size, 0);
		QueryPerformanceCounter(&t_before);
		quickSort(bigRandArray, test_size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_ms = ((double)t_diff * 1000 / freq.QuadPart); // in msec
		elps_time_quickSort_ms = elapsed_time_ms;
		shuffleBigArray(bigRandArray, test_size);
		QueryPerformanceCounter(&t_before);
		mergeSort(bigRandArray, test_size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_ms = ((double)t_diff * 1000 / freq.QuadPart); // in msec
		elps_time_mergeSort_ms = elapsed_time_ms;
		if (test_size > BIG_ARRAY_THRESHOLD)
		{
			printf("%10d %15.2lf %15.2lf %15s %15s\n", test_size, elps_time_quickSort_ms, elps_time_mergeSort_ms, "-", "-");
			continue; // prohibit selection sorting for big array
		}
		shuffleBigArray(bigRandArray, test_size);
		QueryPerformanceCounter(&t_before);
		selectionSort(bigRandArray, test_size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_ms = ((double)t_diff * 1000 / freq.QuadPart); // in msec
		elps_time_selectSort_ms = elapsed_time_ms;
		shuffleBigArray(bigRandArray, test_size);
		QueryPerformanceCounter(&t_before);
		insertSort(bigRandArray, test_size);
		QueryPerformanceCounter(&t_after);
		t_diff = t_after.QuadPart - t_before.QuadPart;
		elapsed_time_ms = ((double)t_diff * 1000 / freq.QuadPart); // in msec
		elps_time_insertSort_ms = elapsed_time_ms;
		printf("%10d %15.2lf %15.2lf %15.2lf %15.2lf\n", test_size, elps_time_quickSort_ms, elps_time_mergeSort_ms, elps_time_insertSort_ms, elps_time_selectSort_ms);
		free(bigRandArray);
	}
	drawLine('=', 82);
}